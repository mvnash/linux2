#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

#include "utils_v2.h"

#define KEY 685
#define KEYSEM 675
#define PERM 0666

int main(int argc, char const *argv[])
{
    if (strcmp(argv[1], "-c") == 0)
    {
        sshmget(KEY, sizeof(char)*10, IPC_CREAT | IPC_EXCL | PERM);
        sem_create(KEYSEM, 1, PERM, 1);
    }
    else if (strcmp(argv[1], "-d") == 0)
    {
        int shm_id = sshmget(KEY, sizeof(char)*10, 0);
        int semId = sem_get(KEYSEM, 1);

        sshmdelete(shm_id);
        sem_delete(semId);
    }
}
