/**
 * @brief Classement dans l'ordre alphabérique des noms de fichiers contenus dans une
 * répertoire et ses sous-répertoires.
 * 
 * Utilisation : trier <répertoire>
 * 
 * @author E. Chaput
 * @date 10/2000 modified 11/2024
 */

#include <stdio.h>
#include <stdlib.h>   /* malloc */
#include <string.h>
#include <pthread.h>
#include <liste-noms-mt.h>
#include <tri-fichier.h>

typedef void * (*ThreadMain)(void *);

int main(int argc, char * argv[])
{
   RechercheNomsFichiers   recherche;
   ListeTrieeNoms        * listeTriee = NULL;
   
   /* Initialisation de la structure de recherche */
   recherche.liste = creerListeNoms();

   /* Traitement des paramètres */
   if (argc == 2) {
      recherche.nomRepertoire = argv[1];
   } else {
      printf("Usage : %s <répertoire>\n", argv[0]);
      exit(1);
   }

   /* On remplit la liste */
   chercherFichiers(&recherche);
   
   /* On trie */
   listeTriee = trier(recherche.liste);

   /* On affiche la liste tri�e */
   if (listeTriee) {
      afficherListeTrieeNoms(*listeTriee);
   }

   return 0;
}
