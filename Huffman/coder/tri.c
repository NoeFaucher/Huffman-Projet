#include <stdio.h>
#include <stdlib.h>
#include "tri.h"

void echange(lettre* tab,int i,int j){
	lettre a = tab[i];
	tab[i] = tab[j];
	tab[j] = a;
}

void trirapid(lettre* tab,int debut,int fin){
	if(debut<fin){
		int pivot = piv(tab,debut,fin);
		trirapid(tab,debut,pivot-1);
		trirapid(tab,pivot+1,fin);
	}
}

int piv(lettre* tab, int debut,int fin){
	int pivot = debut;

	for(int i=debut;i<=fin;i++){
		if(tab[pivot].occ<tab[i].occ){
			echange(tab,pivot,pivot+1);
			if(i!= pivot+1){
				echange(tab,i,pivot);
			}
			pivot++;
		}
	}
	return(pivot);
}
