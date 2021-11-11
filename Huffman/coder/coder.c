#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_coder.h"

#define SAMPLE " etaonihsrldumwyfgpbvkjxqz!\"#$%&\'()*+,-./0123456789:;>=<?@{}|~[]_^ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int main(int argc, char const *argv[]) {
  int taille = (int) strlen(SAMPLE);

  char* phrase = "Bonjour je m'appelle Noe !";
  lettre* tab = alloc(taille);
  tab = init(tab,taille);
  char a;
  char b;

  for(int i = 0; i<taille;i++){
    a =tab[i].val;
    b =tab[i].occ;
    printf(" %c : %d \n",a,b);
  }

  for(int i=0;i<(int) strlen(phrase);i++)
    tab = compte_occ(phrase[i],tab,92);

  printf("\n");
  for(int i = 0; i<taille;i++){
    a =tab[i].val;
    b =tab[i].occ;
    printf(" %c : %d \n",a,b);
  }

  return 0;
}
