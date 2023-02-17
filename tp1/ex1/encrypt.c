#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "crypt.h"
#include "utils_v1.h"

int main(int argc, char const *argv[])
{
    char* ligneAEncrypter = readLine();

    printf("%s", encrypt(ligneAEncrypter));     

    free(ligneAEncrypter);
    return 0;
}
