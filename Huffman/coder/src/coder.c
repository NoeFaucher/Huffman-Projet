#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "coder.h"


int coder(char* path_file,char* path_hfzip) {
  int taille = (int) strlen(SAMPLE);

  arbre* tab_arb_temp = alloc_arb(taille);


  init_default_arb(tab_arb_temp,taille);

  // COMPTE LES OCCURENCES DANS LE TEXTE

  compte_occ_txt(path_file,tab_arb_temp,taille);
  if(tab_arb_temp ==NULL){   //Verifie s'il y a une erreur dans compte_occ_txt
    printf("Erreur comptage d'occurence");
    return -1;
  }

  //TRI LE TABLEAU EN FONCTION DU NOMBRE OCCURENCE
  trirapid(tab_arb_temp,0,taille-1);


  int i = 0;
  int new_taille = 0;
  while(tab_arb_temp[i]->val.occ != 0){
    new_taille++;
    i++;
  }

  arbre* tab_arb = alloc_arb(new_taille);

  lettre* tab_let = alloc_let(new_taille);

  init_fin_arb(tab_arb_temp, tab_arb, new_taille);

  //
  //Aff_tab(tab_arb,new_taille);
  //

  cp_let_arb(tab_arb,tab_let,new_taille);

  arbre arb_huff = malloc(sizeof(noeud));
  arb_huff = ArbreFromTab(tab_arb,new_taille);



  init_code(arb_huff,tab_let,new_taille);

  //Aff_tab(tab_let,new_taille);
  file_header(tab_let,new_taille,path_hfzip);
  encoder(tab_let,new_taille,path_file,path_hfzip);


  Free_Tab_arb(tab_arb,new_taille);

  return 0;
}
