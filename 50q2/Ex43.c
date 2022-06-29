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

ABin cloneMirror (ABin a) {
    ABin pt=NULL;
    if (a==NULL);
    else {
        ABin aux=(ABin) malloc(sizeof(struct nodo));
        aux->valor=a->valor;
        aux->esq=aux->dir=NULL;
        pt=aux;
        pt->esq=cloneMirror(a->dir);
        pt->dir=cloneMirror(a->esq);
    }
    return pt;
}