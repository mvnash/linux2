#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "cryptPolybe.h"
#include "utils_v1.h"

int main(int argc, char const *argv[])
{
printf("Entrez une phrase à crypter (CAPS LOCK ONLY):\n");
    char* ligneAEncrypter = readLine();
    char* ligneCryptee = encrypt(ligneAEncrypter);

    printf("%s", ligneCryptee);     

    free(ligneCryptee);
    free(ligneAEncrypter);
    return 0;
}
