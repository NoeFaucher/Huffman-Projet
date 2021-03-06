#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions_coder.h"


/* *************************************************** */
/*         Fonctions sur les tableaux d'arbres        */
/* *************************************************** */

void ajout_occ_carac(char l, arbre* tab, int taille){
  char* sample = SAMPLE;
  for(int i =0; i < taille;i++){
    if(l == sample[i]){
      tab[i]->val.occ++;
      break;
    }
  }
}

void compte_occ_txt(char* path, arbre* tab, int taille){
  FILE* fichier = fopen(path,"r");
  if(fichier == NULL){  // Verifie s'il n'y a pas d'erreur avec l'ouverture du fichier
    tab = NULL;
  }else{
    char caractere;
    do{
      caractere = fgetc(fichier);
      ajout_occ_carac(caractere,tab,taille);
    }while(caractere != EOF);

    fclose(fichier);
  }
}

void init_fin_arb(arbre* tab_temp, arbre* tab, int taille ){
  for(int i = 0; i < taille; i++){
    tab[i] = tab_temp[taille-1-i];
  }
}

void init_default_arb(arbre* tab, int taille){
  char* sample = SAMPLE;
  for(int i = 0; i<taille;i++){
    tab[i]->val.caractere = sample[i];
    tab[i]->val.occ = 0;
    tab[i]->val.code = "";
    tab[i]->fg = NULL;
    tab[i]->fd = NULL;
  }
}

/* *************************************************** */
/*             Fonctions sur les arbres               */
/* *************************************************** */

int Existence(lettre l, arbre a){
  if(a==NULL){
    return 0;
  }else if(EstFeuille(a)){
    return (l.caractere == a->val.caractere);
  }else{
    return (Existence(l,a->fg) || Existence(l,a->fd));
  }
}

char* seek_code(arbre a,lettre l,char* code){
  if(EstFeuille(a)){
    return code;
  }else if(Existence(l,a->fg)){
    //printf("code : %s",code);
    return seek_code(a->fg,l,Append(code,"0")); //Append(code,"0")
  }else if(Existence(l,a->fd)){
    return seek_code(a->fd,l,Append(code,"1")); //Append(code,"1")
  }else{
    return "";
  }
}

/* *************************************************** */
/*       Fonctions sur les tableaux de lettres         */
/* *************************************************** */

void init_code(arbre huff, lettre* tab, int taille_tab){
  for(int i =0;i<taille_tab;i++){
    tab[i].code = seek_code(huff,tab[i],"");
  }
}

void cp_abr_let(arbre* tab_abr, lettre* tab_let, int taille){
  for(int i =0;i<taille;i++){
    tab_let[i].caractere = tab_abr[i]->val.caractere;
    tab_let[i].occ = tab_abr[i]->val.occ;
    tab_let[i].code = tab_abr[i]->val.code;
  }
}

void file_header(lettre* tab,int taille,char* path_dest){
  FILE* fichier_hfzip = fopen(path_dest,"w+");
  for(int i=0;i<taille-1;i++){
    fprintf(fichier_hfzip,"%c:%d;",tab[i].caractere,tab[i].occ);
  }
  fprintf(fichier_hfzip,"%c:%d\n",tab[taille-1].caractere,tab[taille-1].occ);

  fclose(fichier_hfzip);
}

char* carac_to_code(lettre* tab, int taille, char c){
  for(int i =0;i<taille;i++){
    if(tab[i].caractere == c){
      return tab[i].code;
    }
  }
  return "#err#";
}

void encoder(lettre* tab, int taille, char* path_src, char* path_dest){
  FILE* fichier_txt = fopen(path_src,"r");
  FILE* fichier_hfzip = fopen(path_dest,"a");

  char caractere = fgetc(fichier_txt);

  while(caractere != EOF){

    fputs(carac_to_code(tab,taille,caractere),fichier_hfzip);

    caractere = fgetc(fichier_txt);
  }

  fclose(fichier_txt);
  fclose(fichier_hfzip);
}

/* *************************************************** */
/*             Fonctions suppl??mentaires                */
/* *************************************************** */

void Aff_infixe(arbre a){
  if(a != NULL){
    Aff_infixe(a->fg);
    printf("%d ",a->val.occ);
    Aff_infixe(a->fd);
  }else{
    printf("NULL ");
  }
}

void Aff_tab(arbre* tab,int taille){
  for(int i=0;i<taille;i++){
    //printf("%c : %d \n",tab[i].caractere,tab[i].occ);
    //printf("%c : %d , %s\n",tab[i].caractere,tab[i].occ,tab[i].code);
    //printf("%d : %d \n",i,tab[i]->val.occ);
    //printf("%c : %d \n",tab[i]->val.caractere,tab[i]->val.occ);
    printf("%d : ",i);
    Aff_infixe(tab[i]);
    printf("\n");

  }
  printf("\n");
}
