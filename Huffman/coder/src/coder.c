#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_coder.h"
#include "tri.h"

#define SAMPLE " etaonihsrldumcwyfgpbvkjxqz!\"#$%&\'()*+,-./0123456789:;>=<?@{}|~[]_^ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int main(int argc, char const *argv[]) {
  int taille = (int) strlen(SAMPLE);

  char* phrase = "  llllllllll mmmmmmmm   cc  n";
  arbre* tab_temp = alloc(taille);

  init_default(tab_temp,taille);

  // COMPTE LES OCCURENCES DANS LE TEXTE
  for(int i=0;i<(int) strlen(phrase);i++)
    compte_occ(phrase[i],tab_temp,92);

  //TRI LE TABLEAU EN FONCTION DU NOMBRE OCCURENCE
  trirapid(tab_temp,0,taille-1);

  int i = 0;
  int new_taille = 0;
  while(tab_temp[i]->val.occ != 0){
    new_taille++;
    i++;
  }
  arbre* tab = alloc(new_taille);

  init_fin(tab_temp, tab, new_taille);
  Aff_tab(tab,new_taille);


  arbre arb_huff = ArbreFromTab(tab,new_taille);

  Aff_infixe(arb_huff);
  printf("\n");

  Free_Tab(tab,new_taille);
  return 0;
}
