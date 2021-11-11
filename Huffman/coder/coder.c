#include <stdio.h>
#include <stdlib.h>
#include "fonctions_coder.h"


int main(int argc, char const *argv[]) {
  char* phrase = "Bonjour je m'appelle Noe !";
  lettre* tab = alloc(92);
  tab = init(tab,92);
  char a;
  char b;

  for(int i = 0; i<92;i++){
    a =tab[i].val;
    b =tab[i].occ;
    printf(" %c : %d \n",a,b);
  }

  for(int i=0;i<26;i++)
    tab = compte_occ(phrase[i],tab,92);

  printf("\n");
  for(int i = 0; i<92;i++){
    a =tab[i].val;
    b =tab[i].occ;
    printf(" %c : %d \n",a,b);
  }
  return 0;
}
