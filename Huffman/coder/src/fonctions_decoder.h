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
/*             Focntions suplémentaires                */
/* *************************************************** */

int ChartoInt(char* str);

// retourn a à la puissance b
// Avec a!=0 ou b!=0
int power(int a,int b);

#endif
