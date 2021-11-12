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

lettre* alloc(int taille){
  lettre* tab = malloc(taille * sizeof(lettre));
  return tab;
}

void init(lettre* tab, int taille){
  char* sample = " etaonihsrldumwyfgpbvkjxqz!\"#$%&\'()*+,-./0123456789:;>=<?@{}|~[]_^ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(int i = 0; i<taille;i++){
    tab[i].val = sample[i];
    tab[i].occ = 0;
  }
}


void compte_occ(char l, lettre* tab, int taille){
  char* sample = " etaonihsrldumwyfgpbvkjxqz!\"#$%&\'()*+,-./0123456789:;>=<?@{}|~[]_^ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(int i =0; i < taille;i++){
    if(l == sample[i]){
      tab[i].occ++;
      break;
    }
  }
}
