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
volatile sig_atomic_t cmpt = 0;

void sigusr1_handler(int sig)
{
    const size_t sz = strlen(text);
    write(1, text, sz);
    cmpt++;

    if (cmpt == 7)
    {
        end = 1;
    }
}

volatile sig_atomic_t pereMort = 0;

void sigchld1_handler(int sig)
{
    static const char *const textPere = "Fin du père\n";
    write(1, textPere, strlen(textPere));
    pereMort = 1;
}

//***************************************************************************
// CHILD CODE
//***************************************************************************

void child_handler()
{
    /* PROCESSUS ENFANT */

    while (end == 0)
    {
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

    // initialisation de la structure sigchld
    struct sigaction action2 = {0};
    action2.sa_handler = sigchld1_handler;
    // action.sa_flags = 0;

    // armement du signal SUGUSR1
    int ret = sigaction(SIGUSR1, &action, NULL);
    checkNeg(ret, "erreur sigaction 1");

    // armement du signal SIGCHLD
    ret = sigaction(SIGCHLD, &action2, NULL);
    checkNeg(ret, "erreur sigchld 1");

    pid_t childId = fork_and_run0(child_handler);

    /* PROCESSUS PARENT */

    while (pereMort == 0)
    {
        sleep(1);
        ret = kill(childId, SIGUSR1);
        checkNeg(ret, "erreur kill SIGUSR1");
    }

    int statut;
    swaitpid(childId, &statut, 0);
    printf("Mon fils %d s'est terminé avec le statut: %d\n", childId, WEXITSTATUS(statut));
}