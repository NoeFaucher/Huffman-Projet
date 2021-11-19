#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_coder.h"
#include "tri.h"

#define SAMPLE " etaonihsrldumwyfgpbvkjxqz!\"#$%&\'()*+,-./0123456789:;>=<?@{}|~[]_^ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int main(int argc, char const *argv[]) {
  int taille = (int) strlen(SAMPLE);

  char* phrase = "Bonjour je m'appelle Noe abvubdndkndslncqkjnc posdnflkn zjndcponslkjbzvi iodfburvci oieuvi oiduvhohuzo  hoqiurvugao uhaodivf :: ; ;rk % feo * !";
  arbre* tab_temp = alloc(taille);

  init(tab_temp,taille);

  // COMPTE LES OCCURENCES DANS LE TEXTE
  for(int i=0;i<(int) strlen(phrase);i++)
    compte_occ(phrase[i],tab_temp,92);

  //TRI LE TABLEAU EN FONCTION DU NOMBRE OCCURENCE
  trirapid(tab_temp,0,strlen(SAMPLE)-1);

  int i = 0;
  int new_taille = 0;
  while(tab_temp[i]->val.occ != 0){
    new_taille++;
    i++;
  }

  arbre* tab = alloc(new_taille);

  init_fin(tab_temp, tab, new_taille);

  free(tab_temp);


  return 0;
}
