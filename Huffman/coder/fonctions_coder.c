#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_coder.h"


/*
switch (variable) {
  case 'a':
    ajout dans tableau +1:a ;
    break;
}
*/

arbre* alloc(int taille){
  arbre* tab = malloc(taille * sizeof(arbre));
  return tab;
}

void init(arbre* tab, int taille){
  char* sample = " etaonihsrldumwyfgpbvkjxqz!\"#$%&\'()*+,-./0123456789:;>=<?@{}|~[]_^ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(int i = 0; i<taille;i++){
    tab[i]->val.val = sample[i];
    tab[i]->val.occ = 0;
    tab[i]->fg = NULL;
    tab[i]->fd = NULL;
  }
}

void compte_occ(char l, arbre* tab, int taille){
  char* sample = " etaonihsrldumwyfgpbvkjxqz!\"#$%&\'()*+,-./0123456789:;>=<?@{}|~[]_^ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(int i =0; i < taille;i++){
    if(l == sample[i]){
      tab[i]->val.occ++;
      break;
    }
  }
}

void init_fin(arbre* tab_temp, arbre* tab, int taille ){
  for(int i = 0; i < taille; i++){
    tab[i] = tab_temp[taille-i];
  }
}

arbre CreerArbre(lettre val, arbre filsgauche ,arbre filsdroit){
  arbre a = malloc(sizeof(noeud));
  a->val = val;
  a->fg = filsgauche;
  a->fd = filsdroit;

  return a;
}

int EstFeuille(arbre a){
  if (a->fg ==NULL && a->fd == NULL){
    return 1;
  }else{
    return 0;
  }
}

arbre ArbreFromTab_R(arbre* tab,int taille,int k){
  
}

arbre ArbreFromTab(arbre* tab,int taille{
  ArbreFromTab_R(tab,taille,0);
}
