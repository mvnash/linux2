#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "messages.h"
#include "utils_v2.h"

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
  /* retrieve player name */
  printf("Bienvenue dans le programe d'inscription au serveur de jeu\n");
  printf("Pour participer entrez votre nom :\n");
  StructMessage msg;
  int ret = sread(0, msg.messageText, MAX_PSEUDO);
  msg.messageText[ret - 1] = '\0';
  msg.code = INSCRIPTION_REQUEST;

  int sockfd = initSocketClient(SERVER_IP, SERVER_PORT);
  swrite(sockfd, &msg, sizeof(msg));

  /* wait server response */
  sread(sockfd, &msg, sizeof(msg));

  if (msg.code == INSCRIPTION_OK)
  {
    printf("Réponse du serveur : Inscription acceptée\n");
  }
  else if (msg.code == INSCRIPTION_KO)
  {
    printf("Réponse du serveur : Inscription refusée\n");
  }

  sclose(sockfd);
  return 0;
}
