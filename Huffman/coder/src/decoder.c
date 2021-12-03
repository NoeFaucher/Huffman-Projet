#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "decoder.h"

int decoder(char* path_hfzip, char* path_file){

  int taille_tab = compteur_tab(path_hfzip);

  lettre* tab_let = alloc_let(taille_tab);

  read_file_header(tab_let,path_hfzip);

  //Récupération du tableau depuis l'en tête du fichier
  if(tab_let == NULL){
    printf("Erreur dans la récuperation du tableau d'iteration.\n");
    return -1;
  }
  //Création de l'arbre d'Huffman

  arbre* tab_abr = alloc_arb(taille_tab);

  arbre huff;

  cp_let_arb(tab_let,tab_abr,taille_tab);

  //Aff_tab(tab_abr,taille_tab);

  huff = ArbreFromTab(tab_abr,taille_tab);

  //Aff_infixe(huff);

  if(huff == NULL){
    printf("Erreur dans la création de l'arbre d'Huffman.\n");
    return -1;
  }

  //Décodage du fichier et le mettre directement dans le nouveau fichier

  decode(huff,path_hfzip,path_file);



  if(1){
    printf("Erreur dans la récuperation du tableau d'iteration.\n");
    return -1;
  }


  return 0;
}
