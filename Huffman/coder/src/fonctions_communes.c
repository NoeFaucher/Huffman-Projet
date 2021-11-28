#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions_communes.h"


/* *************************************************** */
/*         Focntions sur les tableaus d'arbres         */
/* *************************************************** */

arbre* ArbreFromTab_R(arbre* tab,int taille){
  arbre arb = NULL;
  lettre l;
  l.occ = tab[0]->val.occ +tab[1]->val.occ;
  arb = CreerArbre(l,tab[0],tab[1]);
  int new_taille = taille-1;
  arbre* new_tab = alloc_arb(new_taille);

  if(new_taille == 1){
    new_tab[0]=arb;
    return new_tab;
  }else{
    int i=2;
    for(;i<taille;i++){
      if(arb->val.occ > tab[i]->val.occ){
        new_tab[i-2] = tab[i];
      }else{
        new_tab[i-2] = arb;
        break;
      }
    }
    if(i==taille){
      new_tab[i-2]= arb;
    }else{
      for(int j=i;j<taille;j++){
        new_tab[j-1] = tab[j];
      }
    }
    return(ArbreFromTab_R(new_tab,new_taille));
  }
}

arbre ArbreFromTab(arbre* tab,int taille){
ArbreFromTab_R(tab,taille);
  return ArbreFromTab_R(tab,taille)[0];
}

/* *************************************************** */
/*       Focntions sur les tableaus de lettres         */
/* *************************************************** */

void cp_let_arb(arbre* tab_abr, lettre* tab_let, int taille){
  for(int i =0;i<taille;i++){
    tab_let[i].caractere = tab_abr[i]->val.caractere;
    tab_let[i].occ = tab_abr[i]->val.occ;
    tab_let[i].code = tab_abr[i]->val.code;
  }
}

/* *************************************************** */
/*             Focntions suplémentaires                */
/* *************************************************** */

char* Append(char* a,char* b){

  if(a == ""){
    return b;
  }

  int taille_a = strlen(a);
  int taille_b = strlen(b);

  int taille_res = taille_a +taille_b;
  char* res = malloc(taille_res*sizeof(char));

  for(int i=0;i<taille_a;i++){
    res[i]=a[i];
  }
  for(int j=0;j<taille_b;j++){
    res[j+taille_a]=b[j];
  }

  return res;
}
