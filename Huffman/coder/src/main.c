#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "coder.h"
#include "decoder.h"
#include "fonctions_communes.h"
//#define SAMPLE " etaonihsrldumcwyfgpbvkjxqz!\"#$%&\'()*+,-./0123456789:;>=<?@{}|~[]_^ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int main(int argc, char* argv[] ) {
  printf("argc : %d\n",argc);
  for(int i=0;i<argc;i++){
    printf("%s\n",argv[i]);
    printf("  len : %d\n", (int) strlen(argv[i]));
  }
  printf("\n");
  printf("..............\n");

  if(argc == 1){
    printf("\n");
    printf("Erreur dans la commande:\n");
    printf("  Pas assez d'argument\n");
    printf("Pour plus d'information utilisé la comande suivante :\n");
    printf("   %s -h\n",argv[0]);
    printf("\n");
    return 0;
  }else if(argc >1 && argv[1][0]!= '-'){
    printf("\n");
    printf("Erreur dans la commande:\n");
    printf("  Pas d'option\n");
    printf("Pour plus d'information utilisé la comande suivante :\n");
    printf("   %s -h\n",argv[0]);
    printf("\n");
    return 0;
  }else if(argc==2 && ((int) strlen(argv[1])) ==2 && argv[1][1]=='h'){
    printf("\n");
    printf("Le manuel d'utilisation de la commande %s\n",argv[0]);
    printf("\n");
    return 0;
  }else if(argc >2 && ((int) strlen(argv[1])) ==2 && argv[1][0]== '-'){
    switch (argv[1][1]) {
      case 'h':
        printf("\n");
        printf("Erreur dans la commande:\n");
        printf("  Trop d'option\n");
        printf("Pour plus d'information utilisé la comande suivante :\n");
        printf("   %s -h\n",argv[0]);
        printf("\n");
        break;
      case 'c':
        break;
      case 'd':
        break;
      default :
        printf("\n");
        printf("Erreur dans la commande:\n");
        printf("  La commande n'exite pas\n");
        printf("Pour plus d'information utilisé la comande suivante :\n");
        printf("   %s -h\n",argv[0]);
        printf("\n");
        break;
    }
  }




/*

  char* path_file = "h2g2.txt";
  char* path_hfzip = "h2g2.hfzip";

  int a = 2;
  //printf("%s\n",mode);
  if(a== 1){
    //printf("hello\n");
    if (coder(path_file,path_hfzip)){
      printf("Erreur de codage de %s\n",path_file);
      return -1;
    }
  }


  if(a == 2){
    if (decoder(path_hfzip,"new_file.txt")){
      printf("Erreur de codage de %s\n",path_file);
      return -1;
    }
  }

*/
  return 0;
}
