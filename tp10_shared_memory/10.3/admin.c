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
#define PERM 0666

int main(int argc, char const *argv[])
{
    if (strcmp(argv[1], "-c"))
    {
        int shm_id = sshmget(KEY, sizeof(int), IPC_CREAT | IPC_EXCL | PERM);

        int semId = sem_create(KEYSEM, 1, PERM, 1);
    }
    else if (strcmp(argv[1], "-d"))
    {
        // Il faut trouver cmt recup les id
        // sshmdelete(shm_id);
        // sem_delete(semId);
    }
}
