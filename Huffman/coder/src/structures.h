#ifndef _STRUCTURES_H_
#define  _STRUCTURES_H_

/* Structures lettre et structure arbre
 *
 * Fonctions liées aux structures.
 *
 */

/*

*/
typedef struct lettre{
  char caractere;
  int occ;
  char* code;
} lettre;

/*

*/
typedef struct noeud noeud;
struct noeud{
  lettre val;
  noeud* fg;
  noeud* fd;
};
typedef noeud* arbre;


/* *************************************************** */
/*         Focntions pour les tableaus d'arbres        */
/* *************************************************** */

arbre* alloc_arb(int taille);

void Free_Tab_arb(arbre* tab,int taille);

arbre CreerArbre(lettre val, arbre filsgauche ,arbre filsdroit);

/* *************************************************** */
/*             Fonctions sur les arbres               */
/* *************************************************** */

int EstFeuille(arbre a);

/* *************************************************** */
/*       Focntions pour les tableaus de lettres        */
/* *************************************************** */

lettre* alloc_let(int taille);

void Free_Tab_let(lettre* tab);

#endif
