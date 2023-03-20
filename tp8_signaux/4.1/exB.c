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

static const char *const text = "signal SIGUSR1 reçu !\n";

volatile sig_atomic_t end = 0;

void sigusr1_handler(int sig)
{
    const size_t sz = strlen(text);
    write(1, text, sz);

    end = 1;
}

//***************************************************************************
// CHILD CODE
//***************************************************************************

void child_handler()
{
    /* PROCESSUS ENFANT */

    while (end == 0)
    {
        printf("Je (fils) dors\n");
        sleep(1);
    }
}

//***************************************************************************
// MAIN
//***************************************************************************

int main()
{
    // initialisation de la structure sigaction
    struct sigaction action = {0};
    action.sa_handler = sigusr1_handler;
    // action.sa_flags = 0;

    // armement du signal SUGUSR1
    int ret = sigaction(SIGUSR1, &action, NULL);
    checkNeg(ret, "erreur sigaction 1");

    pid_t childId = fork_and_run0(child_handler);

    /* PROCESSUS PARENT */
    pid_t pid = getpid();
    printf("Je suis le processus pere (PID %d) - ", pid);

    printf("envoi du signal SIGUSR1 à mon fils (PID %d)\n", childId);
    ret = kill(childId, SIGUSR1);
    checkNeg(ret, "erreur kill SIGUSR1");

    int statut;
    swaitpid(childId, &statut, 0);
    printf("Mon fils %d s'est terminé avec le statut: %d\n", childId, WEXITSTATUS(statut));
}