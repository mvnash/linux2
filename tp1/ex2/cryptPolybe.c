#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "cryptPolybe.h"

static char square[8][8] =
    {{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
     {'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'},
     {'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'},
     {'Y', 'Z', '0', '1', '2', '3', '4', '5'},
     {'6', '7', '8', '9', ' ', '!', '"', '#'},
     {'$', '%', '&', '\'', '(', ')', '*', '+'},
     {',', '-', '.', '/', ':', ';', '<', '='},
     {'>', '?', '@', '[', '\\', ']', '^', '_'}};

char *encrypt(char *msg)
{
    char *text = malloc(sizeof(char) * (3 * strlen(msg) + 1));

    for (int i = 0; i < strlen(msg); i++)
    {

        for (int ligne = 0; ligne < 8; ligne++)
        {
            for (int colonne = 0; colonne < 8; colonne++)
            {
                if (msg[i] == square[ligne][colonne])
                {
                    text[3 * i] = '0' + ligne;
                    text[3 * i + 1] = '0' + colonne;
                    text[3 * i + 2] = ' ';
                    break;
                }
            }
        }
    }
    text[3 * strlen(msg)] = 0;
    return text;
}

char *decrypt(char *msg)
{
    char *text = malloc(sizeof(char) * (strlen(msg) / 3 + 1));

    for (int i = 0; i < strlen(msg); i += 3)
    {
        text[i / 3] = square[(int)msg[i]-'0'][(int)msg[i + 1]-'0'];
    }
    text[strlen(msg)/3] = 0;
    return text;
}
