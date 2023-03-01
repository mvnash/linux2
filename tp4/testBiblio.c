#include <stdlib.h>
#include <stdio.h>

#include "biblio.h"

// qsort - solution 1 (cf. exemple à la fin de la page: man qsort)
int cmp (const void *l1, const void *l2) {
   return comparerLivre((struct Livre*) l1, (struct Livre*) l2);
}

// Programme principal

int main (int argc, char **argv) {
   struct Livre *maBib= NULL;
   int nbreLivre = 0;
   int tailleP = 0;
   struct Livre unLivre;

   while (lireLivre(&unLivre)) {
      if (!ajouterLivre(&maBib, unLivre, &nbreLivre, &tailleP))
         perror("Erreur ajout de livre");
		
      getchar();  // lecture de ligne vide
   }
   afficherBib(maBib, nbreLivre);
	
   // qsort - solution 1 (cf. exemple dans man qsort)
   qsort(maBib, nbreLivre, sizeof(struct Livre), cmp);

   // qsort - solution 2
   // une explication sur la généricité et qsort est disponible sur https://youtu.be/xQBefPZw2jA
   //qsort(maBib, nbreLivre, sizeof(struct Livre), (fctcmp)comparerLivre);

   printf("Après tri: ");
   afficherBib(maBib, nbreLivre);
   free(maBib);
}
