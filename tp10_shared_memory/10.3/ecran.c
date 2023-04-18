#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

#include "utils_v2.h"

#define KEY 683
#define KEYSEM 672

int main(int argc, char const *argv[])
{
    int shm_id = sshmget(KEY, sizeof(int) * 2, 0);
    int semId = sem_get(KEYSEM, 1);

    int *compteurDistributeur = sshmat(shm_id);

    if (compteurDistributeur[0] == compteurDistributeur[1])
    {
        printf("Il n'y a plus personne!\n");
        return 0;
    }

    sem_down0(semId);
    compteurDistributeur[1]++;
    sem_up0(semId);
    
    printf("Ecran : personne suivante = %d\n", compteurDistributeur[1]);
}
