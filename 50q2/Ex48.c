#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

ABin newABin (int r, ABin e, ABin d){
	ABin new = (ABin) malloc (sizeof (struct nodo));

	if (new!=NULL){
		new->valor = r;
		new->esq   = e;
		new->dir   = d;
	}
	return new;
}

void removeMaiorA (ABin *a) {
    ABin tmp;
    if ((*a)!=NULL) {
        while ((*a)->dir!=NULL) a=&((*a)->dir);
        if((*a)->esq!=NULL) {
          tmp=(*a);
          (*a)=(*a)->esq;
          free(tmp);
        }
        else (*a)=NULL;
    }
}