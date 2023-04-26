#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>

#include "utils_v2.h"

#define INPUT_FILE "sitemap.txt"
#define PERMS 0644
#define WEB_SERVER "ochoquet.be"
#define WEB_SERVER_PORT 80
#define BUFFER_SIZE 80

// PRE: ServerIP : a valid IP address
//      ServerPort: a valid port number
// POST: on success connects a client socket to ServerIP:port
//       return socket file descriptor
//       on failure, displays error cause and quits the program
int initSocketClient(char * serverIP, int serverport)
{
  int sockfd = ssocket();
  sconnect(serverIP, serverport, sockfd);
  return sockfd;
}

int main(int argc, char **argv)
{
  size_t nbChar;
  int fd;
  char ligne[BUFFER_SIZE];

  fd = sopen(INPUT_FILE, O_RDONLY, 0);
  // checkNull(file, "open sitemap error");

  char ip[18];
  hostname_to_ip(WEB_SERVER, ip);
  printf("IPv4 %s : %s\n", WEB_SERVER, ip);
  FILE *file = fdopen(fd, "r");

  while ((fgets(ligne, BUFFER_SIZE, file)) != NULL)
  {
    printf("Ligne : %s ,strlen :%lu\n", ligne, strlen(ligne));

    char pageName[BUFFER_SIZE];
    ligne[strlen(ligne) - 1] = '\0';
    sprintf(pageName, "%s", strrchr(ligne, '/') + 1);
    printf("Page Name : %s\n", pageName);

    int sockfd = initSocketClient(ip, WEB_SERVER_PORT);
    // No need to check: exits program on failure
    // checkNeg(sockfd,"socket init client error");

    char request[2 * BUFFER_SIZE];
    sprintf(request, "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", ligne, WEB_SERVER);
    swrite(sockfd, request, strlen(request));

    int fdHTMLPage = sopen(pageName, O_RDWR | O_TRUNC | O_CREAT, PERMS);

    char response[BUFFER_SIZE];
    while ((nbChar = sread(sockfd, response, BUFFER_SIZE)) > 0)
    {
      nwrite(fdHTMLPage, response, nbChar);
    }

    sclose(sockfd);
    sclose(fdHTMLPage);
  }
}
