/* Envoi d'un signal SUGUSR1 du processus père à son fils */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "utils_v2.h"

//***************************************************************************
// SIGUSR1 handler (fils)
//***************************************************************************

void sig_handler(int sig)
{
    const char *const signame = strsignal(sig);
    size_t len = strlen(signame);

    if (write(1, signame, len * sizeof(char)) != len)
    {
        // on devrqait perror
        perror("erreur write sighandler");
    }
}

//***************************************************************************
// MAIN
//***************************************************************************

int main()
{
    // initialisation de la structure sigaction
    struct sigaction action = {0};
    action.sa_handler = sig_handler;
    // action.sa_flags = 0;

    // armement des 32 premiers signaux avec le sigaction au dessus

    for (int i = 1; i <= 31; i++)
    {
        if (i == 9 || i == 19)
        {
            continue;
        }
        int ret = sigaction(i, &action, NULL);
        checkNeg(ret, "erreur sigaction 1");
    }

    printf("pid %d\n", getpid());
    while (true)
    {
        write(1, ".", 1);
        sleep(1);
    }
}