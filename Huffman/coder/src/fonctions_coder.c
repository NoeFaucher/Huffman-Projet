#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_coder.h"


/*
switch (variable) {
  case 'a':
    ajout dans tableau +1:a ;
    break;
}
*/

arbre* alloc(int taille){
  arbre* tab = malloc(taille * sizeof(arbre));
  for(int i=0;i<taille;i++){
    tab[i]=malloc(sizeof(noeud));
  }
  return tab;
}

void Free_Tab(arbre* tab,int taille){
  for(int i=0;i<taille;i++){
    free(tab[i]);
  }
  free(tab);
}

void init_default(arbre* tab, int taille){
  char* sample = SAMPLE;
  for(int i = 0; i<taille;i++){
    tab[i]->val.caractere = sample[i];
    tab[i]->val.occ = 0;
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
  if(fichier == NULL){
    tab = NULL;
  }
  
  char caractere;
  int i =0;
  do{
    i++;
    caractere = fgetc(fichier);
    compte_occ_carac(caractere,tab,taille);
  }while(caractere != EOF);

  fclose(fichier);
}

void init_fin(arbre* tab_temp, arbre* tab, int taille ){
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

int EstFeuille(arbre a){
  if (a->fg ==NULL && a->fd == NULL){
    return 1;
  }else{
    return 0;
  }
}

arbre* ArbreFromTab_R(arbre* tab,int taille){
  arbre arb;
  lettre l;
  l.occ = tab[0]->val.occ +tab[1]->val.occ;
  arb = CreerArbre(l,tab[0],tab[1]);
  int new_taille = taille-1;
  arbre* new_tab = alloc(new_taille);

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
  return (ArbreFromTab_R(tab,taille))[0];
}

void Aff_infixe(arbre a){
  if(a != NULL){
    Aff_infixe(a->fg);
    printf("%d ",a->val.occ);
    Aff_infixe(a->fd);
  }
}

void Aff_tab(arbre* tab,int taille){
  for(int i=0;i<taille;i++){
    //printf("%d ,",tab[i]->val.occ);
    printf("%c : %d \n",tab[i]->val.caractere,tab[i]->val.occ);
  }
  printf("\n");
}
