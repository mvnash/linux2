#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "cryptPolybe.h"
#include "utils_v1.h"

int main(int argc, char const *argv[])
{
    printf("Entrez une phrase cryptée :\n");
    char* ligneADecrypter = readLine();
    char* ligneDecryptee = decrypt(ligneADecrypter);

    printf("%s", ligneDecryptee);

    free(ligneDecryptee);
    free(ligneADecrypter);
    return 0;
}
