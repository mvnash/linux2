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


    sem_down0(semId);
    compteurDistributeur[0]++;
    sem_up0(semId);
    
    printf("Distributeur : prochain ticket = %d\n", compteurDistributeur[0]);
}
