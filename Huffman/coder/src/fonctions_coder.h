#ifndef _FONCTIONS_CODER_
#define  _FONCTIONS_CODER_
/*

*/
typedef struct lettre{
  char caractere;
  int occ;
} lettre;
/*

*/
typedef struct noeud noeud;
struct noeud{
  lettre val;
  noeud* fg;
  noeud* fd;
};
typedef noeud* arbre;

/* *************************************************** */

arbre* alloc(int taille);

void Free_Tab(arbre* tab,int taille);

void init_default(arbre* tab, int taille);

void compte_occ(char l, arbre* tab, int taille);

// Met les lettres du tableau temporaire avec plus de 0 occurence dans un tableau trié dans l'ordre croissant
void init_fin(arbre* tab_temp, arbre* tab, int taille );

arbre CreerArbre(lettre val, arbre filsgauche ,arbre filsdroit);

int EstFeuille(arbre a);

arbre* ArbreFromTab_R(arbre* tab,int taille);

// retourne l'arbre final
arbre ArbreFromTab(arbre* tab,int taille);

void Aff_infixe(arbre a);

void Aff_tab(arbre* tab,int taille);

#endif
