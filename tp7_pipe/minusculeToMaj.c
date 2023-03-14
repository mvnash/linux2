#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#include "utils_v2.h"

int main(int argc, char const *argv[])
{
    // 1/ Création du pipe
    int pipefd[2];
    int ret = pipe(pipefd);
    checkNeg(ret, "pipe error");

    // 2/ Création de l'enfant
    int childId = sfork();

    // PARENT
    if (childId > 0)
    {
        // 3/ Cloture du descripteur pour la lecture
        ret = close(pipefd[0]);
        checkNeg(ret, "close error");

        // 4// On écrit un entier pour le fils
        char bufferRead[256];
        int nbRead = 0;
        while ( (nbRead = read(0, bufferRead, 256)) > 0)
        {
            int nbChar = write(pipefd[1], bufferRead, nbRead * sizeof(char));
            checkCond(nbChar < 0, "write error");
        }

        // 5/ On clôture le côté écriture du pipe
        ret = close(pipefd[1]);
        checkNeg(ret, "close error");
    }
    // FILS
    else
    {
        // 3// Cloture du descripteur d'écriture
        int ret = close(pipefd[1]);
        checkNeg(ret, "close error");

        // 4// On attend un entier de la part du père
        char bufferRead[256];
        int nbChar = read(pipefd[0], bufferRead, 256 * sizeof(char));
        checkCond(nbChar <= 0, "read error");

        int i = 0;
        while (bufferRead[i] != '\n')
        {
            bufferRead[i] = toupper(bufferRead[i]);
            i++;
        }

        printf("%s", bufferRead);

        // 5/ On clôture le côté lecture du pipe
        ret = close(pipefd[0]);
        checkNeg(ret, "close error");
    }
}
