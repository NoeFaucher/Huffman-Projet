#ifndef _FONCTIONS_CODER_
#define  _FONCTIONS_CODER_
/*

*/
typedef struct lettre{
  char val;
  int occ;
} lettre;
/*
"é"
""
uint8_t
*/
typedef struct noeud noeud;
struct noeud{
  lettre val;
  noeud* fg;
  noeud* fd;
};
typedef noeud* arbre;

lettre* alloc(int taille);

lettre* init(lettre* tab, int taille);

lettre* compte_occ(char l, lettre* tab, int taille);



#endif
