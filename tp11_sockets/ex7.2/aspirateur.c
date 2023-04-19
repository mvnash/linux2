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

#define BACKLOG 5

// PRE: ServerIP : a valid IP address
//      ServerPort: a valid port number
// POST: on success connects a client socket to ServerIP:port
//       return socket file descriptor
//       on failure, displays error cause and quits the program
int initSocketClient(char * serverIP, int serverport)
{
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    printf("Socket client error");
    exit(1);
  }

  struct sockaddr_in addr;
  memset(&addr,0,sizeof(addr));

  addr.sin_family = AF_INET;
  addr.sin_port = htons(serverport);
  inet_aton(serverIP,&addr.sin_addr);
  int returnConnect = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));
  if(returnConnect < 0) {
    printf("Connect client error");
    exit(1);
  }

  return sockfd;
}

int main(int argc, char **argv)
{
    char ip[17];
    hostname_to_ip("ochoquet.be",ip);

    int file = sopen("sitemap.txt", O_RDONLY ,0777);
    char page[1000];
    while (readLimitedLineOnFile(file,page,1000))
    {
        printf("%s\n",page);
        //initSocketClient(ip,80);
        sprintf(page,"%s",strrchr(page,'/')+1);
        printf("%s\n", page);
    }
    
    
}
