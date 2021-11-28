#ifndef _FONCTIONS_CODER_
#define  _FONCTIONS_CODER_

#define SAMPLE ((char*)" etaonihsrldumcwyfgpbvkjxqz\n!\"#$%&\'()*+,-./0123456789:;>=<?@{}|~[]_^ABCDEFGHIJKLMNOPQRSTUVWXYZ")

#include "structures.h"

/* Les fonctions ici sont les fonctions nécessaires uniquements
 * pour le codage.
 *
 * Les fonctions communes au codage et au decodage sont
 * dans "fonctions_communes.h".
 * Les structures arbre et lettre sont dans "structures.h" avec
 * les fonctions liées à elles.
 */


/* *************************************************** */
/*         Focntions sur les tableaus d'arbres        */
/* *************************************************** */

void compte_occ_carac(char l, arbre* tab, int taille);

void compte_occ_txt(char* path, arbre* tab, int taille);

// Met les lettres du tableau temporaire avec plus de 0 occurence dans un tableau trié dans l'ordre croissant
void init_fin_arb(arbre* tab_temp, arbre* tab, int taille );

void init_default_arb(arbre* tab, int taille);

/* *************************************************** */
/*             Fonctions sur les arbres                */
/* *************************************************** */

int Existence(lettre l, arbre a);

char* seek_code(arbre a, lettre l, char* code);

/* *************************************************** */
/*       Focntions sur les tableaus de lettres         */
/* *************************************************** */

void init_code(arbre huff, lettre* tab, int taille_tab);

void file_header(lettre* tab,int taille,char* path_dest);

char* carac_to_code(lettre* tab, int taille, char c);

void encoder(lettre* tab, int taille, char* path_src,char* path_dest);

/* *************************************************** */
/*             Focntions suplémentaires                */
/* *************************************************** */

void Aff_infixe(arbre a);

void Aff_tab(lettre* tab,int taille);


#endif
