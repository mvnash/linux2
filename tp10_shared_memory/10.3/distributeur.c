#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

#include "utils_v2.h"

#define KEYSEM 672
#define PERM 0666

int main(int argc, char const *argv[])
{
    int i = 1;
    while (true)
    {
        printf("Distributeur : prochain ticket = %d",i);
        i++;
    }
}
