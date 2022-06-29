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

int quantosMaiores (ABin a, int x) {
    int r=0;
    if (a==NULL);
    else {
        if (a->valor>x) r++;
        r+=quantosMaiores(a->esq,x);
        r+=quantosMaiores(a->dir,x);
    }
    return r;
}