#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>

#include "utils_v2.h"

#define KEY 685
#define KEYSEM 675

int main(int argc, char const *argv[])
{
    int shm_id = sshmget(KEY, sizeof(char) * 10, 0);
    int semId = sem_get(KEYSEM, 1);

    char *texte = sshmat(shm_id);

    sem_down0(semId);
    for (size_t i = 0; i < 10; i++)
    {
        texte[i] = argv[1][i];
    }

    sem_down0(semId);
    printf("%s\n", texte);
}
