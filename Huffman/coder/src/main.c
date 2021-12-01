#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "coder.h"
#include "decoder.h"
#include "fonctions_communes.h"
//#define SAMPLE " etaonihsrldumcwyfgpbvkjxqz!\"#$%&\'()*+,-./0123456789:;>=<?@{}|~[]_^ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int main(int argc, char const *argv[]) {

  char* path_file = "test.txt";
  char* path_hfzip = "test.hfzip";

  int mode = 2;
  if(mode == 1){
    if (coder(path_file,path_hfzip)){
      printf("Erreur de codage de %s\n",path_file);
      return -1;
    }
  }


  if(mode == 2){
    if (decoder(path_hfzip,"new_file.txt")){
      printf("Erreur de codage de %s\n",path_file);
      return -1;
    }
  }


  return 0;
}
