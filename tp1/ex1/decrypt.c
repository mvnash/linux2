#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "crypt.h"
#include "utils_v1.h"

int main(int argc, char const *argv[])
{
    char* ligneADecrypter = readLine();

    printf("%s", decrypt(ligneADecrypter));     

    free(ligneADecrypter);
    return 0;
}
