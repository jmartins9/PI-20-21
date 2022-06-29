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

int contaFolhas (ABin a) {
    int r=0;
    if (a==NULL);
    else if (a->esq==NULL && a->dir==NULL) r+=1;
    else {
        r+=contaFolhas(a->esq);
        r+=contaFolhas(a->dir);
    }
    return r;
}