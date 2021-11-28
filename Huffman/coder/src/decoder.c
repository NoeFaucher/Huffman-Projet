#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "decoder.h"

#include "fonctions_coder.h"

int decoder(char* path_hfzip, char* path_file){

  lettre* tab = alloc_let(16);


  read_file_header(tab,path_hfzip);

  Aff_tab(tab,16);
  //Récupération du tableau de puis l'entete du fichier
  if(1){
    printf("Erreur dans la récuperation du tableau d'iteration.\n");
    return -1;
  }
  //Création de l'arbre d'Huffman

  if(1){
    printf("Erreur dans la création de l'arbre d'Huffman.\n");
    return -1;
  }

  //Décodage du fichier et le mettre directement dans le nouveau fichier
  if(1){
    printf("Erreur dans la récuperation du tableau d'iteration.\n");
    return -1;
  }


  return 0;
}
