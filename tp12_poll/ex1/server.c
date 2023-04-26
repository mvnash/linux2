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

#define MAX_PLAYERS 2
#define BACKLOG 5
#define INSCRIPTION_TIME 15

typedef struct Player
{
  char pseudo[MAX_PSEUDO];
  int sockfd;
} Player;

Player tabPlayers[MAX_PLAYERS];
int nbPlayers;
volatile sig_atomic_t end = 0;

char *codeToString(int code)
{
  if (code == PAPIERS)
  {
    return "PIERRE";
  }
  if (code == PIERRE)
  {
    return "PAPIERS";
  }
  if (code == CISEAUX)
  {
    return "CISEAUX";
  }
  return "????"
}

void endServerHandler(int sig)
{
  end = 1;
}

void sigALRMHandler(int sig)
{
  if (nbPlayers != 2)
  {
    const char *const text = "Pas assez de joueurs pour commencer.";
    size_t len = strlen(text);
    write(1, text, len * sizeof(char));
    end = 1;
  }
}

void terminate(Player *tabPlayers, int nbPlayers)
{
  printf("\nJoueurs inscrits : \n");
  for (int i = 0; i < nbPlayers; i++)
  {
    printf("  - %s inscrit\n", tabPlayers[i].pseudo);
  }
  exit(0);
}

void winner(Player p1, Player p2, char *winner)
{
  if (p1.shot == PAPIERS && p2.shot == PAPIERS)
  {
    strcpy(winner, "EGALITE");
  }
  if (p1.shot == PIERRE && p2.shot == PIERRE)
  {
    strcpy(winner, "EGALITE");
  }
  if (p1.shot == CISEAUX && p2.shot == CISEAUX)
  {
    strcpy(winner, "EGALITE");
  }
  // TODO
}

/**
 * PRE:  serverPort: a valid port number
 * POST: on success, binds a socket to 0.0.0.0:serverPort and listens to it ;
 *       on failure, displays error cause and quits the program
 * RES: return socket file descriptor
 */
int initSocketServer(int serverPort)
{
  int sockfd = ssocket();

  /* no socket error */

  sbind(serverPort, sockfd);

  /* no bind error */
  slisten(sockfd, BACKLOG);

  /* no listen error */
  return sockfd;
}

int main(int argc, char **argv)
{
  StructMessage msg;
  nbPlayers = 0;

  sigset_t set;
  ssigemptyset(&set);
  sigaddset(&set, SIGINT);
  sigaddset(&set, SIGTERM);
  ssigprocmask(SIG_BLOCK, &set, NULL);

  ssigaction(SIGALRM, sigALRMHandler);
  ssigaction(SIGTERM, endServerHandler);
  ssigaction(SIGINT, endServerHandler);

  int sockfd = initSocketServer(SERVER_PORT);
  printf("Le serveur tourne sur le port : %i \n", SERVER_PORT);

  // setsockopt -> to avoid Address Already in Use
  int option = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(int));

  ssigprocmask(SIG_UNBLOCK, &set, NULL);

  alarm(INSCRIPTION_TIME);

  while (!end)
  {

    /* client trt */
    int newsockfd = accept(sockfd, NULL, NULL);
    if (nbPlayers == 2)
    {
      break;
    }

    if (end)
    {
      terminate(tabPlayers, nbPlayers);
    }

    read(newsockfd, &msg, sizeof(msg));
    if (end)
    {
      terminate(tabPlayers, nbPlayers);
    }

    printf("Inscription demandée par le joueur : %s\n", msg.messageText);
    if (nbPlayers < MAX_PLAYERS)
    {
      msg.code = INSCRIPTION_OK;
      strcpy(tabPlayers[nbPlayers].pseudo, msg.messageText);
      tabPlayers[nbPlayers].sockfd = newsockfd;
      nbPlayers++;
    }
    else
    {
      msg.code = INSCRIPTION_KO;
    }

    write(newsockfd, &msg, sizeof(msg));
    printf("Nb Inscriptions : %i\n", nbPlayers);
  }

  end = 0;
  while (!end)
  {
    strcpy("Le jeu commence\n", msg.messageText);
    msg.code = GO_JEU;
  }

  sclose(sockfd);
}
