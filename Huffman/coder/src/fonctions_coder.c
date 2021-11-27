#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_coder.h"


/* *************************************************** */
/*         Focntions pour les tableaus d'arbres        */
/* *************************************************** */

arbre* alloc_arb(int taille){
  arbre* tab = malloc(taille * sizeof(arbre));
  for(int i=0;i<taille;i++){
    tab[i]=malloc(sizeof(noeud));
  }
  return tab;
}

void Free_Tab_arb(arbre* tab,int taille){
  for(int i=0;i<taille;i++){
    free(tab[i]);
  }
  free(tab);
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

void compte_occ_carac(char l, arbre* tab, int taille){
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
      compte_occ_carac(caractere,tab,taille);
    }while(caractere != EOF);

    fclose(fichier);
  }
}

void init_fin_arb(arbre* tab_temp, arbre* tab, int taille ){
  for(int i = 0; i < taille; i++){
    tab[i] = tab_temp[taille-1-i];
  }
}

arbre CreerArbre(lettre l, arbre filsgauche ,arbre filsdroit){
  arbre a = malloc(sizeof(noeud));
  a->val = l;
  a->fg = filsgauche;
  a->fd = filsdroit;

  return a;
}

arbre* ArbreFromTab_R(arbre* tab,int taille){
  arbre arb = NULL;
  lettre l;
  l.occ = tab[0]->val.occ +tab[1]->val.occ;
  arb = CreerArbre(l,tab[0],tab[1]);
  int new_taille = taille-1;
  arbre* new_tab = alloc_arb(new_taille);

  if(new_taille == 1){
    new_tab[0]=arb;
    return new_tab;
  }else{
    int i=2;
    for(;i<taille;i++){
      if(arb->val.occ > tab[i]->val.occ){
        new_tab[i-2] = tab[i];
      }else{
        new_tab[i-2] = arb;
        break;
      }
    }
    if(i==taille){
      new_tab[i-2]= arb;
    }else{
      for(int j=i;j<taille;j++){
        new_tab[j-1] = tab[j];
      }
    }
    return(ArbreFromTab_R(new_tab,new_taille));
  }
}

arbre ArbreFromTab(arbre* tab,int taille){
ArbreFromTab_R(tab,taille);
  return ArbreFromTab_R(tab,taille)[0];
}

/* *************************************************** */
/*             Fonctions pour les arbres               */
/* *************************************************** */

int EstFeuille(arbre a){
  return (a->fg ==NULL && a->fd == NULL);
}

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
    return seek_code(a->fg,l,Append(code,"0"));
  }else if(Existence(l,a->fd)){
    return seek_code(a->fd,l,Append(code,"1"));
  }else{
    return "";
  }
}

/* *************************************************** */
/*       Focntions pour les tableaus de lettres        */
/* *************************************************** */

lettre* alloc_let(int taille){
  lettre* tab = malloc(taille * sizeof(lettre));
  return tab;
}

void Free_Tab_let(lettre* tab){
  free(tab);
}

void cp_let_arb(arbre* tab_abr, lettre* tab_let, int taille){
  for(int i =0;i<taille;i++){
    tab_let[i].caractere = tab_abr[i]->val.caractere;
    tab_let[i].occ = tab_abr[i]->val.occ;
    tab_let[i].code = tab_abr[i]->val.code;
  }
}

void init_code(arbre huff, lettre* tab, int taille_tab){
  for(int i =0;i<taille_tab;i++){
    tab[i].code = seek_code(huff,tab[i],"");
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
/*             Focntions suplémentaires                */
/* *************************************************** */

void Aff_infixe(arbre a){
  if(a != NULL){
    Aff_infixe(a->fg);
    printf("%d ",a->val.occ);
    Aff_infixe(a->fd);
  }
}

void Aff_tab(lettre* tab,int taille){
  for(int i=0;i<taille;i++){
    printf("%c : %d , %s\n",tab[i].caractere,tab[i].occ,tab[i].code);
    //printf("%c : %d \n",tab[i]->val.caractere,tab[i]->val.occ);
  }
  printf("\n");
}

char* Append(char* a,char* b){

  if(a == ""){
    return b;
  }

  int taille_a = strlen(a);
  int taille_b = strlen(b);

  int taille_res = taille_a +taille_b;
  char* res = malloc(taille_res*sizeof(char));

  for(int i=0;i<taille_a;i++){
    res[i]=a[i];
  }
  for(int j=0;j<taille_b;j++){
    res[j+taille_a]=b[j];
  }

  return res;
}
