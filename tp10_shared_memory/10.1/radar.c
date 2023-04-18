#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>

#include "utils_v2.h"

#define KEY 368
#define KEYSEM 651
#define PERM 0666

int main(int argc, char const *argv[])
{
    int nbSecondes = 0;

    int shm_id = sshmget(KEY, sizeof(int), IPC_CREAT | IPC_EXCL | PERM);
    int *z = sshmat(shm_id);

    int semId = sem_create(KEYSEM, 1, PERM,1)

    while (nbSecondes <= 60)
    {
        sleep(3);
        sem_down0(semId);
        *z = randomIntBetween(0,100);
        sem_up0(semId);
        nbSecondes += 3;
    }
    sshmdelete(shm_id);
    sem_delete(semId);
    return 0;
}
