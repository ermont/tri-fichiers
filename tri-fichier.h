#ifndef __TRI_FICHIER
#define __TRI_FICHIER

#include <liste-noms.h>
#include <liste-triee-noms.h>

/**
 * Structure de données manipulée par une recherche
 */
typedef struct {
   char      * nomRepertoire;
   ListeNoms * liste;
} RechercheNomsFichiers;

/**
 * @brief Recherche de tous les noms des fichiers contenus dans un 
 * répertoire (et ses sous répertoire)
 */
void chercherFichiers(RechercheNomsFichiers * recherche);

/**
 * @brief Tri d'une liste de noms.
 *    La valeur de retour est un pointeur vers la liste triées de noms 
 *    contenant les noms présents dans la list passée en paramètre
 * @param liste : la liste à trier
 * @return ListeTrieeNoms : une liste de noms triée
 */
ListeTrieeNoms * trier(ListeNoms * liste);

#endif
