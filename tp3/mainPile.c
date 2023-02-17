#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Pile.h"
#include "utils_v1.h"

void ajouterUneValeur(Pile p);
void popPile(Pile p);

int main(int argc, char const *argv[])
{
    Pile pile = initPile();
    int choix;
    int valeurAjouter;
    int valeurSuppr;

    while (true)
    {
        printf("1 - Ajouter sur la pile : \n");
        printf("2 - Supprimer sur la pile : \n");
        printf("3 - Afficher la pile : \n");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            printf("Entrez une valeur : \n");
            scanf("%d", &valeurAjouter);
            push(&pile, valeurAjouter);
            break;
        case 2:
            valeurSuppr = pop(&pile);
            printf("Valeur du pop : %d\n", valeurSuppr);
            break;
        case 3:
            afficherPile(pile);
            break;

        default:
            printf("Choix non valide");
            break;
        }
    }
    return 0;
}
