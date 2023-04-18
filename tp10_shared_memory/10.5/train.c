#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

#include "utils_v2.h"
#include "ipc_conf.h"

static int semId; 
static int shm_id;
static int *tableauPID;

void sigusr1_handler(int sig)
{
    static char text[500];
    sprintf(text, "[%s] START CROSSING THE SWITCH", getTime());
    const size_t sz = strlen(text);
    write(1, text, sz);
    sem_up0(semi)
}

int main(int argc, char const *argv[])
{
    if (argc <= 1)
    {
        printf("[%s] Erreur : Pas d'argument de direction\n", getTime());
        return 0;
    }

    shm_id = sshmget(KEY, sizeof(int) * 2, 0);
    semId = sem_get(KEYSEM, 1);

    *tableauPID = sshmat(shm_id);

    // initialisation de la structure sigaction
    struct sigaction action = {0};
    action.sa_handler = sigusr1_handler;
    // action.sa_flags = 0;

    // armement du signal SUGUSR1
    int ret = sigaction(SIGUSR1, &action, NULL);
    checkNeg(ret, "erreur sigaction 1");

    // Reservation aiguillage
    printf("[%s] WAIT UNTIL THE SWITCH IS FREE", getTime());
    sem_down0(semId);

    // Ecriture pid dans memoire partagee
    tableauPID[1] = getpid();

    // Envoie signal de direction
    if (strcmp(argv[1], "R") == 0)
    {
        int ret = kill(tableauPID[0], SIGUSR2);
        checkNeg(ret, "erreur kill SIGUSR2");
    }
    else if (strcmp(argv[1], "L") == 0)
    {
        int ret = kill(tableauPID[0], SIGUSR1);
        checkNeg(ret, "erreur kill SIGUSR1");
    }

    // Attente SIGUSR1 du switch
    printf("[%s] WAIT UNTIL THE SWITCH IS ON THE CORRECT SIDE", getTime());
}
