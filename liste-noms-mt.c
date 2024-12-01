/**
 * @brief Implantation du module ListeNoms
 * 
 * @author E. Chaput
 * @date 10/2000
 */

#include <liste-noms-mt.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include <assert.h>
#include <pthread.h>

ListeNoms * creerListeNoms(void)
{
  ListeNoms * result = (ListeNoms *) malloc(sizeof(ListeNoms));
  initialiserListeNoms(result);
  return result;
}

void initialiserListeNoms(ListeNoms * f)
{
   f->premier = NULL;
   f->dernier = NULL;
}

void insererNom(ListeNoms * f, Nom nom)
{
   CelluleNom * nc = (CelluleNom *)malloc(sizeof(CelluleNom));

   nc->nom = strdup(nom);

   /* Mise dans la chaine */
   nc->suivant = NULL;

   if (f->dernier != NULL) {
      f->dernier->suivant = nc;
   }
   f->dernier = nc;

   /* Si c'est le seul, c'est aussi le premier */
   if (f->premier == NULL) {
      f->premier = nc;
   }

}

void extraireNom(ListeNoms * f, Nom * nom)
{
   CelluleNom * cv = f->premier; // Cellule vide à détruire

   if (f->premier) {
     /* Son suivant devient le premier */
     *nom = f->premier->nom;
     f->premier = f->premier->suivant;

     /* Si c'était le dernier */
     if (f->dernier == cv) {
        f->dernier = NULL;
     }                                                                                         
 
     free(cv);
   } else {
     *nom = NULL;
   }
}

void afficherListeNoms(ListeNoms f)
{
   CelluleNom * cc = f.premier;

   while (cc != NULL) {
      printf("%s\n", cc->nom);
      cc = cc->suivant;
   }
}

bool listeNomsVide(ListeNoms *f)
{
   return (f->premier == NULL);
}
