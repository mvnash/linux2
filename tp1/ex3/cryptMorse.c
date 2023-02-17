#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "cryptMorse.h"

static char *tradTab[52] =
    {"A", ".-",
     "B", "-...",
     "C", "-.-.",
     "D", "-..",
     "E", ".",
     "F", "..-.",
     "G", "--.",
     "H", "....",
     "I", "..",
     "J", ".---",
     "K", "-.-",
     "L", ".-..",
     "M", "--",
     "N", "-.",
     "O", "---",
     "P", ".--.",
     "Q", "--.-",
     "R", ".-.",
     "S", "...",
     "T", "-",
     "U", "..-",
     "V", "...-",
     "W", ".--",
     "X", "-..-",
     "Y", "-.--",
     "Z", "--.."};

char *encrypt(char *msg)
{
    char *text = malloc(sizeof(char) * ((4 * strlen(msg)) + (3 * strlen(msg)) + 1));
    if (text == NULL)
        return NULL;

    for (int i = 0; i < strlen(msg); i++)
    {
        for (int index = 0; index < 52; index += 2)
        {
            if (msg[i] == ' ')
            {
                strcat(text, "   ");
                break;
            }

            if (msg[i] == *tradTab[index])
            {
                strcat(text, tradTab[index + 1]);
                strcat(text, " ");
                break;
            }
        }
    }

    text[(4 * strlen(msg)) + (3 * strlen(msg))] = 0;
    return text;
}

char *decrypt(char *msg)
{
    char *text = malloc(sizeof(char) * ((strlen(msg) / 4) + (strlen(msg) / 3) + 1));
    if (text == NULL)
        return NULL;

    char *chaineProvi = malloc(sizeof(char) * 4);
    if (chaineProvi == NULL)
        return NULL;
    int index = 0;
    int indexProvi = 0;

    while (msg[index] != 0)
    {
        if (msg[index] != ' ')
        {
            chaineProvi[indexProvi] = msg[index];
            indexProvi++;
        }
        else
        {
            indexProvi = 0;
            for (int i = 1; i < 52; i += 2)
            {
                if (strcmp(tradTab[i], chaineProvi) == 0)
                {
                    strcat(text, tradTab[i - 1]);
                    memset(chaineProvi, 0, sizeof(char) * 4);
                    break;
                }
            }
            if (msg[index + 1] == ' ')
            {
                strcat(text, " ");
                index += 2;
            }
        }
        index++;
    }
    free(chaineProvi);
    text[strlen(msg) / 4 + (strlen(msg) / 3)] = 0;
    return text;
}
