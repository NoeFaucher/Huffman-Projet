#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_coder.h"
#include "tri.h"

#define SAMPLE " etaonihsrldumwyfgpbvkjxqz!\"#$%&\'()*+,-./0123456789:;>=<?@{}|~[]_^ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int main(int argc, char const *argv[]) {
  int taille = (int) strlen(SAMPLE);

  char* phrase = "Bonjour je m'appelle Noe abvubdndkndslncqkjnc posdnflkn zjndcponslkjbzvi iodfburvci oieuvi oiduvhohuzo  hoqiurvugao uhaodivf :: ; ;rk % feo * !";
  lettre* tab = alloc(taille);

  init(tab,taille);
  char a;
  char b;

  for(int i = 0; i<taille;i++){
    a =tab[i].val;
    b =tab[i].occ;
    printf(" %c : %d \n",a,b);
  }

  for(int i=0;i<(int) strlen(phrase);i++)
    compte_occ(phrase[i],tab,92);

  trirapid(tab,0,strlen(SAMPLE)-1);

  printf("\n");
  for(int i = 0; i<taille;i++){
    a =tab[i].val;
    b =tab[i].occ;
    printf(" %c : %d \n",a,b);
  }

  return 0;
}
