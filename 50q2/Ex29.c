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

ABin cloneAB (ABin a) {
    ABin cp=NULL;
    if (a==NULL);
    else {
        cp=(ABin) malloc (sizeof (struct nodo));   
        cp->valor=a->valor;
        cp->esq=cloneAB(a->esq);
        cp->dir=cloneAB(a->dir);
    }
    return cp;
}