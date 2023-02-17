#ifndef _BIBLIO_
#define _BIBLIO_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_TITRE 128
#define MAX_AUTEUR 80
#define MAX_EDITEUR 50
#define MAX_LIGNE_LIVRE MAX_TITRE+MAX_AUTEUR+MAX_EDITEUR+50

enum Genre {BD,POESIE,THEATRE,ROMAN,ROMANHIST,LITTERATURE,LITTERATUREETRANGER,SCIENCES,INFORMATIQUE,SCIENCEFICTION,SANTE,HISTOIRE};

struct Livre {
    char titre[MAX_TITRE+1];
    char auteur[MAX_AUTEUR+1];
    long isbn;
    char editeur[MAX_EDITEUR+1];
    int anneeEdit;

    enum Genre genre;    
};


bool lireLivre (struct Livre * l);

enum Genre str2genre (char* s);

char* genre2str(enum Genre g);

char* livre2str(char* s, struct Livre l);

void afficherBiblio (const struct Livre* bib, int taille);

bool ajouterLivre ( struct Livre ** biblio, struct Livre livre, int* nombreLogique, int* taille);

int comparerLivre (const struct Livre* a, const struct Livre* b);

#endif // _BIBLIO_