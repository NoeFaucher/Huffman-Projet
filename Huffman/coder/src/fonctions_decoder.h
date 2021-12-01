#ifndef _FONCTIONS_DECODER_H_
#define  _FONCTIONS_DECODER_H_

#include "structures.h"
#include "fonctions_communes.h"

/* Les fonctions ici sont les fonctions nécessaires uniquements
 * pour le decodage.
 *
 * Les fonctions communes au codage et au decodage sont
 * dans "fonctions_communes.h".
 * Les structures arbre et lettre sont dans "structures.h" avec
 * les fonctions liées à elles.
 */

 /* *************************************************** */
 /*       Focntions sur les tableaus de lettres         */
 /* *************************************************** */

int compteur_tab(char* path_file);

//
//
void read_file_header(lettre* tab,char* path_file);


/* *************************************************** */
/*       Focntions sur les tableaus d'arbres           */
/* *************************************************** */

// copie la valeur de la racine de chaque arbre
// d'un tableau de lettres dans un tableau d'arbres
void cp_let_arb(lettre* tab_let, arbre* tab_abr, int taille);


/* *************************************************** */
/*               Focntions sur les arbres              */
/* *************************************************** */

char seek_char(arbre arb,FILE* fichier_hfzip,char last);

void decode(arbre huff, char* path_hfzip, char* path_file);


/* *************************************************** */
/*             Focntions suplémentaires                */
/* *************************************************** */

int StrtoInt(char* str);

char* ChartoStr(char c);

// retourn a à la puissance b
// Avec a!=0 ou b!=0
int power(int a,int b);

#endif
