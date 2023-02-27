#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "utils_v1.h"
#include "Pile.h"

// methode utilitaire privee
Pile __unit_pile(int v);

Pile initPile()
{
    return NULL;
}

bool pileVide(Pile p)
{
    return p == NULL;
}

bool push(Pile *p, int v)
{
    Pile nvlePile = __unit_pile(v);
    nvlePile->bottom = *p;
    *p = nvlePile;
    return true;
}

int pop(Pile *p)
{
    int value = (*p)->top;
    Pile pointeurfree = (*p);
    *p = (*p)->bottom;
    free(pointeurfree);
    return value;
}

void viderPile(Pile *p)
{
    if (pileVide(*p)) 
    {
        return;
    }
    Pile pile = *p;
    while (pile->bottom != NULL)
    {
        free(pile);
        pile = pile->bottom;
    }
    free(*p);
    *p = NULL;
}

void afficherPile(Pile p)
{
    if (pileVide(p))
    {
        printf("Afficher pile: Pile vide\n");
        return;
    }
    Pile pile = p;
    printf("Pile actuelle : \n%d\n", p->top);

    while (pile->bottom != NULL)
    {
        printf("%d\n", pile->bottom->top);
        pile = pile->bottom;
    }
}

Pile __unit_pile(int v)
{
    // on cree un noeud sur le heap
    Pile p = (Pile)malloc(1 * sizeof(struct SousPile));
    if (p == NULL)
    {
        perror("plus de ram disponible");
        exit(666);
    }
    // on s assure que la memoire soit bien propre
    memset(p, 0, sizeof(struct SousPile));

    // maintenant on peut aller ecrire dans la memoire
    p->top = v;
    p->bottom = initPile();

    return p;
}