/**
 * @brief Interface d'une liste élémentaire de chaînes de caractères
 * 
 * Note : les chaînes de caractères sont copiées dans des zones mémoire
 * allouées lors de l'insertion dans la liste. L'Utilisateur peut donc 
 * détruire ou réutiliser les chaînes passées en paramètres et reçues des 
 * sous-programmes de ce module.
 * 
 */
#ifndef FILE_NOMS
#define FILE_NOMS

#include <nom.h>
#include <stdbool.h>

#include <pthread.h>



/**
 * Type d'une cellule de la liste
 */
typedef struct _CelluleNom {
   Nom                  nom;
   struct _CelluleNom * suivant;
} CelluleNom;

/**
 * Une liste de noms est caractérisée simplement par son premier 
 * et son dernier élément
 */
struct ListeNoms {
   CelluleNom * premier;
   CelluleNom * dernier;
   pthread_mutex_t verrou;
};

typedef struct ListeNoms ListeNoms;

/**
 * @brief Création d'une liste de noms
 * 
 * @return ListeNoms* 
 */
ListeNoms * creerListeNoms(void);

/**
 * @brief Initialisation de la liste de noms
 *
 * Assure
 *    listeNomsVide(*f)
 * 
 * @param f : la liste de noms
 */
void initialiserListeNoms(ListeNoms * f);

/**
 * @brief Insertion d'un nom en fin de liste
 * 
 * @param f : la liste à modifier
 * @param nom : le nom à ajouter
 */
void insererNom(ListeNoms * f, Nom nom);

/**
 * @brief Extraction du premier élément de la liste
 * 
 * @param f : la liste à modifier
 * @param nom : le nom du premier élément ou NULL si la liste est vide
 */
void extraireNom(ListeNoms * f, Nom * nom);

/**
 * @brief Affichage de la liste, du premier au dernier élément
 * un élement par ligne
 * 
 * @param f : la liste à afficher
 */
void afficherListeNoms(ListeNoms f);

/**
 * @brief la liste de noms est-elle vide ?
 * 
 * @param f : la liste
 * @return true si la liste de nom est vide
 * @return false sinon
 */
bool listeNomsVide(ListeNoms *f);

#endif
