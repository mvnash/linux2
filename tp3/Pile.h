#ifndef _PILE_H_
#define _PILE_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct SousPile {
    int          top;
    struct SousPile* bottom;
};

typedef struct SousPile* Pile;

Pile initPile();

bool pileVide(Pile);

bool push(Pile *, int);

int pop(Pile *);

void viderPile(Pile *);

void afficherPile(Pile);

#endif // _PILE_H_