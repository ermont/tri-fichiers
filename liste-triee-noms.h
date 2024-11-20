/**
 * @brief Interface de gestion d'une liste triée de chaînes de caractères (les noms des fichiers)
 * Le tri est celui de strcmp(3)
 * 
 * Note : les chaînes de caractères sont copiées dans des zones mémoire
 * allouées lors de l'insertion dans la liste. L'utilisataur peux donc 
 * détruire ou réutiliser les chaînes passées en paramètres et reçues des
 * sous-programmes de ce module.alignas
 * 
 * @author E. Chaput
 * @date   10/2000
 */

#ifndef LISTE_TRIEE_NOMS
#define LISTE_TRIEE_NOMS

#include <stdbool.h>
#include <nom.h>  /* Pour le type Nom */

/**
 * @brief Type d'une cellule de la chaîne
 */
typedef struct _CelluleTrieeNom {
   Nom nom;
   struct _CelluleTrieeNom * suivant;
} CelluleTrieeNom;

/**
 * @brief Une liste de noms est caractérisée simplement par son premier
 * et son dernier élément
 */
typedef struct {
   CelluleTrieeNom * premier;
   CelluleTrieeNom * dernier;
} ListeTrieeNoms;

/**
 * @brief Initlisation d'une liste de noms triés
 * 
 * @param l 
 */
void initialiserListeTrieeNoms(ListeTrieeNoms * l);

/**
 * @brief Insertion d'un nom dans la liste 
 * 
 * @param l : la liste
 * @param nom : le nom à insérer
 */
void trierNom(ListeTrieeNoms * l, Nom nom);

/**
 * @brief Extraction du premier élément de la lite
 * 
 * @param l : la liste
 * @param nom : le nom extrait
 */
void extrairePremierNom(ListeTrieeNoms * l, Nom * nom);

/**
 * @brief Affichage de la liste, du premier au dernier élément
 * un élément par ligne
 * 
 * @param l : la liste à afficher
 */
void afficherListeTrieeNoms(ListeTrieeNoms l);

/**
 * @brief la liste est-elle vide ?
 * 
 * @param l : la liste
 * @return bool : la liste est vide 
 */
bool listeTrieeVide(ListeTrieeNoms l);
#endif
