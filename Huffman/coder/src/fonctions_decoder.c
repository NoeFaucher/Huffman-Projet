#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions_decoder.h"


/* *************************************************** */
/*       Focntions sur les tableaus de lettres         */
/* *************************************************** */

int compteur_tab(char* path_file){
  int i=1;

  FILE* fichier = fopen(path_file,"r");
  if(fichier==NULL){
    return -1;
  }

  char curent = fgetc(fichier);
  char next = fgetc(fichier);
  char next_next =fgetc(fichier);

  while(!((curent=='\n') && (next !=':'))){
    if(curent == ';' && next_next==':'){
      i++;
    }
    curent =next;
    next = next_next;
    next_next = fgetc(fichier);
    //printf("%d:\n curent : %c\n next : %c\n next_next : %c\n",i,curent,next,next_next);
  }
  fclose(fichier);
  return i;
}

void read_file_header(lettre* tab,char* path_file){
  FILE* fichier = fopen(path_file,"r");

  int finish = 0;

  //char caractere = fgetc(fichier);
  char bin;
  char* occ;
  char next;

  int i =0;


  while(!finish){
    occ = "";

    tab[i].caractere = fgetc(fichier);

    // le ':'
    bin = fgetc(fichier);

    next = fgetc(fichier);
    do{
      occ = Append(occ,&next);
      next = fgetc(fichier);
    }while((next!=';')||(next!='\n'));

    tab[i].occ = ChartoInt(occ);

    if(next!='\n'){
      finish = 1;
    }
    i++;
  }

}

/* *************************************************** */
/*             Focntions suplémentaires                */
/* *************************************************** */

int ChartoInt(char* str){
  int taille = strlen(str);
  int res =0;
  for(int i= 0;i<taille;i++){
    switch (str[i]){
      case '1':
        res += 1*power(10,i);
        break;
      case '2':
        res += 2*power(10,i);
        break;
      case '3':
        res += 3*power(10,i);
        break;
      case '4':
        res += 4*power(10,i);
        break;
      case '5':
        res += 5*power(10,i);
        break;
      case '6':
        res += 6*power(10,i);
        break;
      case '7':
        res += 7*power(10,i);
        break;
      case '8':
        res += 8*power(10,i);
        break;
      case '9':
        res += 9*power(10,i);
        break;
      default :
        res += 0;
        break;
    }
  }
  return res;
}

int power(int a,int b){
  int res=a;
  for(int i=1;i<b;i++){
    res = res*a;
  }
  return res;
}
