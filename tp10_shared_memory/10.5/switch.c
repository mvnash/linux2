#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>

#include "utils_v2.h"
#include "ipc_conf.h"

int main(int argc, char const *argv[])
{
    int shm_id = sshmget(KEY, sizeof(int) * 2, 0);
    int semId = sem_get(KEYSEM, 1);

    int *tableauPID = sshmat(shm_id);


}
