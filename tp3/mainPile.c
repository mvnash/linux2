#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Pile.h"
#include "utils_v1.h"

int main(int argc, char const *argv[])
{
    Pile pile = initPile();
    int choix = -1;
    int valeurAjouter;
    int valeurSuppr;

    while (choix != 0)
    {
        printf("\n");
        printf("0 - Quitter\n");
        printf("1 - Ajouter sur la pile : \n");
        printf("2 - Supprimer sur la pile : \n");
        printf("3 - Afficher la pile : \n");
        scanf("%d", &choix);
        switch (choix)
        {
        case 0:
        viderPile(&pile);
            break;
        case 1:
            printf("\nEntrez une valeur : \n");
            scanf("%d", &valeurAjouter);
            push(&pile, valeurAjouter);
            break;
        case 2:
            valeurSuppr = pop(&pile);
            printf("\nValeur du pop : %d\n", valeurSuppr);
            break;
        case 3:
            afficherPile(pile);
            break;

        default:
            printf("\nChoix non valide");
            break;
        }
        printf("\n");
    }
    return 0;
}
