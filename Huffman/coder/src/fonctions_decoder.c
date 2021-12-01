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

  char next;

  int i =0;

  char* occ;

  while(!finish){
    occ ="";

    tab[i].caractere = fgetc(fichier);

    // le ':'
    bin = fgetc(fichier);

    next = fgetc(fichier);


    do{
    occ = Append(occ,ChartoStr(next));      //ChartoStr(next)
    next = fgetc(fichier);

  }while(!((next==';')||(next=='\n')));

    tab[i].occ = StrtoInt(occ);

    if(next=='\n'){
      finish = 1;
    }
    i++;
  }
  fclose(fichier);
}


/* *************************************************** */
/*       Focntions sur les tableaus d'arbres           */
/* *************************************************** */

void cp_let_arb(lettre* tab_let, arbre* tab_abr, int taille){
  for(int i =0;i<taille;i++){
    tab_abr[i]->val.caractere = tab_let[i].caractere;

    tab_abr[i]->val.occ = tab_let[i].occ;
  }
}


/* *************************************************** */
/*               Focntions sur les arbres              */
/* *************************************************** */

char seek_char(arbre arb,FILE* fichier_hfzip,char last){
  if(EstFeuille(arb)){
    return arb->val.caractere;
  }else{
    if(last != ' '){
      if(last=='0'){
        return seek_char(arb->fg,fichier_hfzip,' ');
      }else{
        return seek_char(arb->fd,fichier_hfzip,' ');
      }
    }else{
      if(fgetc(fichier_hfzip) =='0'){
        return seek_char(arb->fg,fichier_hfzip,' ');
      }else{
        return seek_char(arb->fd,fichier_hfzip,' ');
      }
    }
  }

}

void decode(arbre huff, char* path_hfzip, char* path_file){
  FILE* fichier_hfzip = fopen(path_hfzip,"r");
  FILE* fichier_new = fopen(path_file,"w+");

  char curent = fgetc(fichier_hfzip);
  char next = getc(fichier_hfzip);

  while(!((curent=='\n') && (next !=':'))){


    curent = next;
    next = getc(fichier_hfzip);
  }
  curent = next;

  while(curent != EOF){
    fprintf(fichier_new, "%c", seek_char(huff,fichier_hfzip,curent));
    curent = getc(fichier_hfzip);
  }



  fclose(fichier_hfzip);
  fclose(fichier_new);
}


/* *************************************************** */
/*             Focntions suplémentaires                */
/* *************************************************** */

int StrtoInt(char* str){
  int taille = strlen(str);
  int res =0;
  for(int i= 0;i<taille;i++){
    switch (str[i]){
      case '1':
        res = res+ 1*power(10,taille-1-i);
        break;
      case '2':
        res = res+ 2*power(10,taille-1-i);
        break;
      case '3':
        res = res+ 3*power(10,taille-1-i);
        break;
      case '4':
        res = res+ 4*power(10,taille-1-i);
        break;
      case '5':
        res = res+ 5*power(10,taille-1-i);
        break;
      case '6':
        res = res+ 6*power(10,taille-1-i);
        break;
      case '7':
        res = res+ 7*power(10,taille-1-i);
        break;
      case '8':
        res = res+ 8*power(10,taille-1-i);
        break;
      case '9':
        res = res+ 9*power(10,taille-1-i);
        break;
      default :
        res = res+ 0;
        break;
    }
  }
  return res;
}

char* ChartoStr(char c){
  char* str = (char*) malloc(sizeof(char));
  str[0] =c;
  return str;
}

int power(int a,int b){
  if(b==0){
    return 1;
  }
  int res=a;
  for(int i=1;i<b;i++){
    res = res*a;
  }
  return res;
}
