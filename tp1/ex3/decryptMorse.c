#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "cryptMorse.h"
#include "utils_v1.h"

int main(int argc, char const *argv[])
{
    printf("Entrez une phrase cryptée (doit finir par un espace):\n");
    char* ligneADecrypter = readLine();
    char* ligneDecryptee = decrypt(ligneADecrypter);

    printf("Phrase decryptée ==> %s", ligneDecryptee);

    free(ligneDecryptee);
    free(ligneADecrypter);
    return 0;
}
