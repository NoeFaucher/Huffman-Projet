#ifndef _FONCTIONS_CODER_
#define  _FONCTIONS_CODER_

#define SAMPLE ((char*)" etaonihsrldumcwyfgpbvkjxqz\n!\"#$%&\'()*+,-./0123456789:;>=<?@{}|~[]_^ABCDEFGHIJKLMNOPQRSTUVWXYZ")
/*

*/
typedef struct lettre{
  char caractere;
  int occ;
  char* code;
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
/*         Focntion pour les tableaus d'arbres         */
/* *************************************************** */

arbre* alloc_arb(int taille);

void Free_Tab_arb(arbre* tab,int taille);

void init_default_arb(arbre* tab, int taille);

void compte_occ_carac(char l, arbre* tab, int taille);

void compte_occ_txt(char* path, arbre* tab, int taille);

// Met les lettres du tableau temporaire avec plus de 0 occurence dans un tableau trié dans l'ordre croissant
void init_fin_arb(arbre* tab_temp, arbre* tab, int taille );

arbre CreerArbre(lettre val, arbre filsgauche ,arbre filsdroit);

arbre* ArbreFromTab_R(arbre* tab,int taille);

// retourne l'arbre final
arbre ArbreFromTab(arbre* tab,int taille);

/* *************************************************** */
/*             Fonction pour les arbres                */
/* *************************************************** */

int EstFeuille(arbre a);

int Existence(lettre l, arbre a);

char* seek_code(arbre a, lettre l, char* code);

/* *************************************************** */
/*       Focntion pour les tableaus de lettres         */
/* *************************************************** */

lettre* alloc_let(int taille);

void Free_Tab_let(lettre* tab);

void cp_let_arb(arbre* tab_abr, lettre* tab_let, int taille);

void init_code(arbre huff, lettre* tab, int taille_tab);



/* *************************************************** */

/* *************************************************** */


void Aff_infixe(arbre a);

void Aff_tab(lettre* tab,int taille);

char* Append(char* a,char* b);

#endif
