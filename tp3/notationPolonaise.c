#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Pile.h"
#include "utils_v1.h"

int main(int argc, char const *argv[])
{
    Pile pile = initPile();
    char *ligne = " ";
    int index = 0;
    int valeur1;
    int valeur2;
    int result;

    while (ligne != NULL)
    {
        index = 0;
        ligne = readLine();
        int first_non_digit_offset = strspn(ligne, "0123456789+-*/ ");

        if (first_non_digit_offset != strlen(ligne))
        {
            printf("La ligne contient caractère non supporté\n");
            continue;
        }
        while (ligne[index] != 0)
        {
            printf("%c", ligne[index]);
            switch (ligne[index])
            {
            case '+':

                valeur1 = pop(&pile);
                if (pileVide(pile))
                {
                    printError("Pile vide");
                    break;
                }
                valeur2 = pop(&pile);

                result = valeur2 + valeur1;

                printOk(" = la réponse est : ");
                printf("%d\n", result);

                push(&pile, result);
                break;

            case '-':

                valeur1 = pop(&pile);
                if (pileVide(pile))
                {
                    printError("Pile vide");
                    break;
                }
                valeur2 = pop(&pile);

                result = valeur2 - valeur1;
                printOk(" = la réponse est : ");
                printf("%d\n", result);
                push(&pile, result);
                break;

            case '*':

                valeur1 = pop(&pile);
                if (pileVide(pile))
                {
                    printError("Pile vide");
                    break;
                }
                valeur2 = pop(&pile);

                result = valeur2 * valeur1;
                printOk(" = la réponse est : ");
                printf("%d\n", result);
                push(&pile, result);
                break;

            case '/':
                valeur1 = pop(&pile);
                if (pileVide(pile))
                {
                    printError("Pile vide");
                    break;
                }
                valeur2 = pop(&pile);

                if (valeur1 == 0)
                {
                    push(&pile, valeur2);
                    printError("Division par 0 -> Math Error\n");
                    break;
                }

                result = valeur2 / valeur1;
                printOk(" = la réponse est : ");
                printf("%d\n", result);
                push(&pile, result);
                break;

            case ' ':
                break;

            default:
                push(&pile, ligne[index] - '0');
                break;
            }
            index++;
            // afficherPile(pile);
        }
        viderPile(&pile);
    }
    return 0;
}
