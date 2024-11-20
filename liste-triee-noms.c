/**
 * @brief Implantation d'une liste triée de noms
 * 
 * @author E. Chaput
 * @date   10/2000
 */

#include <liste-triee-noms.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

void initialiserListeTrieeNoms(ListeTrieeNoms * l)
{
   l->premier = NULL;
   l->dernier = NULL;
}

void trierNom(ListeTrieeNoms * l, Nom nom)
{
   CelluleTrieeNom * nc;
   CelluleTrieeNom * cp;

   /* Allocation de la cellule */
   nc = (CelluleTrieeNom *)malloc(sizeof(CelluleTrieeNom));
   if (nc == NULL) {
      perror("malloc ");
      exit(1);
   }

   /* Copie de la donnée */
   nc->nom = strdup(nom);
   if (nc->nom == NULL) {
      perror("strdup ");
      exit(1);
   }

   /* Si c'est le premier */
   if ((l->premier == NULL) || (strcmp(l->premier->nom, nom) >= 0)) {
      nc->suivant = l->premier;
      l->premier = nc;
   /* Cas g�n�ral */
   } else {
      /* On place dans cp la cellule devant précéder nc */
      cp = l->premier;
      while ((cp->suivant != NULL) && (strcmp(cp->suivant->nom, nom) < 0)) {
         cp = cp->suivant;
      }

      /* Mise dans la chaîne */
      nc->suivant = cp->suivant;
      cp->suivant = nc;
   }

   /* Si c'est le seul, c'est aussi le dernier */
   if ((l->dernier == NULL) || (l->dernier->suivant == nc)) {
      l->dernier = nc;
   }
}

void extrairePremierNom(ListeTrieeNoms * l, Nom * nom)
{
   CelluleTrieeNom * cv = l->premier;

   /* Son suivant devient le premier */
   if (l->premier != NULL) {
      *nom = l->premier->nom;
      l->premier = l->premier->suivant;
   } else {
      *nom = NULL;
   }

   /* Si c'était le dernier */
   if (l->dernier == cv) {
      l->dernier = NULL;
   } 

   free(cv);
}

void afficherListeTrieeNoms(ListeTrieeNoms l)
{
   CelluleTrieeNom * cc = l.premier;

   while (cc != NULL) {
      printf("%s\n", cc->nom);
      cc = cc->suivant;
   }
}

bool listeTrieeVide(ListeTrieeNoms l)
{
   return (l.premier == NULL);
}
