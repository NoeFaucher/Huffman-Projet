#ifndef _FONCTIONS_COMMUNES_H_
#define  _FONCTIONS_COMMUNES_H_

#include "structures.h"

/* Les fonctions ici sont les fonctions communes au codage et au decodage
 *
 * Les fonctions liées uniquements au codage sont dans "fonctions_coder.h".
 * Les fonctions liées uniquements au decodage sont dans "fonctions_decoder.h".
 * Les structures arbre et lettre sont dans "structures.h" avec
 * les fonctions liées à elles.
 */

 /* *************************************************** */
 /*         Focntions sur les tableaus d'arbres         */
 /* *************************************************** */

 arbre* ArbreFromTab_R(arbre* tab,int taille);

 // retourne l'arbre final
 arbre ArbreFromTab(arbre* tab,int taille);

 /* *************************************************** */
 /*       Focntions sur les tableaus de lettres         */
 /* *************************************************** */

 // copie la valeur de la racine de chaque arbre
 // d'un tableau d'arbres dans un tableau de lettres
 void cp_let_arb(arbre* tab_abr, lettre* tab_let, int taille);

 /* *************************************************** */
 /*             Focntions suplémentaires                */
 /* *************************************************** */

char* Append(char* a,char* b);


#endif
