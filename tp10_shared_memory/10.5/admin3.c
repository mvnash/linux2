#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

#include "utils_v2.h"
#include "ipc_conf.h"

int main(int argc, char const *argv[])
{
    if (strcmp(argv[1], "-c") == 0)
    {
        sshmget(KEY, sizeof(int)*2, IPC_CREAT | IPC_EXCL | PERM);
        sem_create(KEYSEM, 1, PERM, 1);
    }
    else if (strcmp(argv[1], "-d") == 0)
    {
        int shm_id = sshmget(KEY, sizeof(int)*2, 0);
        int semId = sem_get(KEYSEM, 1);

        sshmdelete(shm_id);
        sem_delete(semId);
    } else
    {
        printf("Utilisez -c pour creer et -d pour supprimer");
    }
    

}
