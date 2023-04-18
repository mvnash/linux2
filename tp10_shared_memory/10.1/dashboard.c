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

    int shm_id = sshmget(KEY, sizeof(int), 0);
    int *z = sshmat(shm_id);

    int semId = semget(KEYSEM, 1, 0);

  //  int semId = sem_create(KEYSEM,1,0666,1);

    while (nbSecondes <= 60)
    {
        sleep(5);
        sem_down0(semId);
        printf("Dashboard : shared mem value: *z = %d\n", *z);
        sem_up0(semId);
        nbSecondes += 5;
    }

    sshmdelete(shm_id);
    sem_delete(semId);
    return 0;
}
