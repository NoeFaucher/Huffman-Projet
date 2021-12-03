#ifndef _FONCTIONS_CODER_
#define  _FONCTIONS_CODER_


// l'ensemble de caractere lu par le programme
// la plupart des caracteres caractere ASCII
#define SAMPLE ((char*)" etaonihsrldumcwyfgpbvkjxqz\n!\"#$%&\'()*+,-./0123456789:;>=<?@{}|~[]_^\\ABCDEFGHIJKLMNOPQRSTUVWXYZ")

#include "structures.h"
#include "fonctions_communes.h"

/* Les fonctions ici sont les fonctions nécessaires uniquements
 * pour le codage.
 *
 * Les fonctions communes au codage et au decodage sont
 * dans "fonctions_communes.h".
 * Les structures arbre et lettre sont dans "structures.h" avec
 * les fonctions liées à elles.
 */


/* *************************************************** */
/*         Focntions sur les tableaus d'arbres         */
/* *************************************************** */

// Fonction qui modifie le tableau et ajoute une occurence
// dans le tableau au caractere corespondant
// Prend un caractere, le tableau d'arbres et la taille du tableau
void ajout_occ_carac(char l, arbre* tab, int taille);

// Fonctions qui parcourt un fichier et pour chaque caractere
// ajoute une occurence dans le tableau au caractere associé (appel de ajout_occ_carac)
void compte_occ_txt(char* path, arbre* tab, int taille);

// Met les lettres du tableau temporaire avec au moins une occurence
// dans un tableau trié dans l'ordre croissant
void init_fin_arb(arbre* tab_temp, arbre* tab, int taille );

// Initialise les valeurs (de type lettre) du tableau d'arbres
// à ses valeurs initiale (met le caractere avec 0 occurence)
void init_default_arb(arbre* tab, int taille);

/* *************************************************** */
/*             Fonctions sur les arbres                */
/* *************************************************** */

// Retourne vrai ou faux si la lettre entrée existe dans l'arbre entrée
// ou dans un de ces descendants
int Existence(lettre l, arbre a);

// Fonction qui parcourt l'arbre de Huffman pour determiner le
// codage d'une lettre donnée. (0:à gauche ou 1:à droite)
// A la fin des recursions retourne le code final de la lettre
char* seek_code(arbre a, lettre l, char* code);

/* *************************************************** */
/*       Focntions sur les tableaus de lettres         */
/* *************************************************** */

// Fonction qui initialise pour chaque élément du tableau
// son codage
void init_code(arbre huff, lettre* tab, int taille_tab);

// Copie la valeur de la racine de chaque arbre
// d'un tableau d'arbres dans un tableau de lettres
void cp_abr_let(arbre* tab_abr, lettre* tab_let, int taille);

// Procedure qui écrit dans un fichier chaque caractere du tableau de
// lettre avec son nombre d'occurence, de la manière suivante :
// "le_caractere:nbr_occurence;" ou pour le dernier élément du tableau
// "le_caractere:nbr_occurence\n"
void file_header(lettre* tab,int taille,char* path_dest);

char* carac_to_code(lettre* tab, int taille, char c);

void encoder(lettre* tab, int taille, char* path_src,char* path_dest);

/* *************************************************** */
/*             Focntions suplémentaires                */
/* *************************************************** */

void Aff_infixe(arbre a);

void Aff_tab(arbre* tab,int taille);


#endif
