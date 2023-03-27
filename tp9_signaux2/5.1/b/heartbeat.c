#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#include "utils_v2.h"

void sigalrmParentHandler(int num)
{
    const char *msg = "Erreur: mon fils est down\n";
    nwrite(1, msg, strlen(msg));

    _exit(EXIT_FAILURE);
}

void sigIntParent(int num){
    const char *msg = "Sigint recu\n";
    nwrite(1, msg, strlen(msg));
}

void sigalrmFilsHandler(int num)
{
    kill(getppid(), SIGUSR1);
    alarm(5);
}

void sigusr1handler(int sig)
{
    const char *msg = "Mon fils est toujours en vie!\n";
    nwrite(1, msg, strlen(msg));

    // reset countdown
    alarm(12);
}

int main(int argc, char const *argv[])
{
    pid_t childID = fork();

    // PERE
    if (childID > 0)
    {
        // initialisation de la structure sigaction
        struct sigaction action = {0};
        action.sa_handler = sigusr1handler;
        // action.sa_flags = 0;

        int ret = sigaction(SIGUSR1, &action, NULL);
        checkNeg(ret, "erreur sigaction 1");

        // initialisation de la structure sigaction
        struct sigaction action3 = {0};
        action3.sa_handler = sigIntParent;
        // action.sa_flags = 0;

        ret = sigaction(SIGINT, &action3, NULL);
        checkNeg(ret, "erreur sigaction 1");

        // initialisation de la structure sigaction
        struct sigaction action2 = {0};
        action2.sa_handler = sigalrmParentHandler;
        // action.sa_flags = 0;

        ret = sigaction(SIGALRM, &action2, NULL);
        checkNeg(ret, "erreur sigaction 1");

        alarm(12);
        /* lancement d'un compte à rebours de 12 secondes */
        while (true)
        {
            sleep(1);
        }
    }
    // FILS
    else
    {

        // initialisation de la structure sigaction
        struct sigaction action = {0};
        action.sa_handler = sigalrmFilsHandler;
        // action.sa_flags = 0;

        int ret = sigaction(SIGALRM, &action, NULL);
        checkNeg(ret, "erreur sigaction 1");

        /* lancement d'un compte à rebours de 5 secondes */
        // TODO
        alarm(5);
        while (true)
        {
            sleep(1);
        }
    }
}
