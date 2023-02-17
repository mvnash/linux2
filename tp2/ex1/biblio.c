#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "utils_v1.h"
#include "biblio.h"

bool lireLivre(struct Livre *l)
{
    printf("Entrez le titre : ");
    readLimitedLine(l->titre, MAX_TITRE);

    printf("Entrez le auteur : ");
    readLimitedLine(l->auteur, MAX_AUTEUR);

    printf("Entrez l'ISBN : ");
    scanf("%ld", l->isbn);

    printf("Entrez l'editeur : ");
    readLimitedLine(l->editeur, MAX_EDITEUR);

    printf("Entrez l'annee d'édition : ");
    scanf("%d", l->anneeEdit);

    printf("Entrez le genre : ");
    char *strGenre;
    readLimitedLine(strGenre, 128);
    l->genre = str2genre(strGenre);
}

enum Genre str2genre(char *s)
{
    enum Genre g;
    if (strcmp(s, "Bande dessinee") == 0)
    {
        return BD;
    }

    if (strcmp(s, "Poesie") == 0)
    {
        return POESIE;
    }

    if (strcmp(s, "Theatre") == 0)
    {
        return THEATRE;
    }

    if (strcmp(s, "Roman") == 0)
    {
        return ROMAN;
    }

    if (strcmp(s, "Roman historique") == 0)
    {
        return ROMANHIST;
    }

    if (strcmp(s, "Litterature francaise") == 0)
    {
        return LITTERATURE;
    }

    if (strcmp(s, "Litterature etrangere") == 0)
    {
        return LITTERATUREETRANGER;
    }

    if (strcmp(s, "Sciences") == 0)
    {
        return SCIENCES;
    }

    if (strcmp(s, "Informatique") == 0)
    {
        return INFORMATIQUE;
    }

    if (strcmp(s, "Science-fiction") == 0)
    {
        return SCIENCEFICTION;
    }

    if (strcmp(s, "Sante") == 0)
    {
        return SANTE;
    }

    if (strcmp(s, "Histoire") == 0)
    {
        return HISTOIRE;
    }

    return NULL;
}

char *genre2str(enum Genre g)
{
    switch (g)
    {
    case 0:
        return "Bande dessinee";
    case 1:
        return "Poesie";
    case 2:
        return "Theatre";
    case 3:
        return "Roman";
    case 4:
        return "Roman Historique";
    case 5:
        return "Litterature francaise";
    case 6:
        return "Litterature etrangere";
    case 7:
        return "Sciences";
    case 8:
        return "Informatique";
    case 9:
        return "Science-fiction";
    case 10:
        return "Sante";
    case 11:
        return "Histoire";
    }
}

char* livre2str(char* s, struct Livre l){
    s = "Auteur : "; // + l.auteur;
}