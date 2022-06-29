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

int iguaisAB (ABin a, ABin b) {
    int r=0;
    int tmp1,tmp2;
    if (a==NULL && b==NULL) r=1;
    else if (a==NULL || b==NULL) r=0;
    else if (a->valor==b->valor) {
        tmp1=iguaisAB(a->esq,b->esq);
        tmp2=iguaisAB(a->dir,b->dir);
        if (tmp1 && tmp2) r=1;
        else r=0;
    }
    return r;
}