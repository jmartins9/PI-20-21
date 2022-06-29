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

int lookupAB (ABin a, int x) {
    int r=0;
    while (a!=NULL && r!=1) {
        if (x<a->valor) a=a->esq;
        else if (x>a->valor) a=a->dir;
        else r=1;
    } 
    return r;
}

