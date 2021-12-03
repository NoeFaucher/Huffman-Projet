#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"


/* *************************************************** */
/*         Fonctions pour les tableaux d'arbres        */
/* *************************************************** */

arbre* alloc_arb(int taille){
  arbre* tab =(arbre*) malloc(taille * sizeof(arbre));
  for(int i=0;i<taille;i++){
    tab[i]=(arbre) malloc(sizeof(noeud));
  }
  return tab;
}

void Free_Tab_arb(arbre* tab,int taille){
  for(int i=0;i<taille;i++){
    free(tab[i]);
  }
  free(tab);
}

arbre CreerArbre(lettre l, arbre filsgauche ,arbre filsdroit){
  arbre a =(arbre) malloc(sizeof(noeud));
  a->val = l;
  a->fg = filsgauche;
  a->fd = filsdroit;

  return a;
}

/* *************************************************** */
/*             Fonctions pour les arbres               */
/* *************************************************** */

int EstFeuille(arbre a){
  return (a->fg ==NULL && a->fd == NULL);
}

/* *************************************************** */
/*       Fonctions pour les tableaux de lettres        */
/* *************************************************** */

lettre* alloc_let(int taille){
  lettre* tab =(lettre*) malloc(taille * sizeof(lettre));
  return tab;
}

void Free_Tab_let(lettre* tab){
  free(tab);
}
