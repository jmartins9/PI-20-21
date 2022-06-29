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


ABin somasAcA (ABin a) {
    ABin pt=NULL;
    ABin tmp1,tmp2;
    if (a==NULL);
    else if (a->esq!=NULL && a->dir!=NULL){        
        tmp1=somasAcA(a->esq); 
        tmp2=somasAcA(a->dir);
        ABin aux=(ABin) malloc(sizeof(struct nodo));
        aux->valor=a->valor+tmp1->valor+tmp2->valor;
        aux->esq=NULL;
        aux->dir=NULL;
        pt=aux;
        
        pt->esq=tmp1;
        pt->dir=tmp2;
    }
    else if (a->esq!=NULL && a->dir==NULL) {
        tmp1=somasAcA(a->esq); 
        ABin aux=(ABin) malloc(sizeof(struct nodo));
        aux->valor=a->valor+tmp1->valor;
        aux->esq=NULL;
        aux->dir=NULL;
        pt=aux;
        pt->esq=tmp1;
    }
    else if (a->esq==NULL && a->dir!=NULL) {
        tmp2=somasAcA(a->dir);
        ABin aux=(ABin) malloc(sizeof(struct nodo));
        aux->valor=a->valor+tmp2->valor;
        aux->esq=NULL;
        aux->dir=NULL;
        pt=aux;
        pt->dir=tmp2;
    }
    else { 
        ABin aux=(ABin) malloc(sizeof(struct nodo));
        aux->valor=a->valor;
        aux->esq=NULL;
        aux->dir=NULL;
        pt=aux;
    }
    return pt;
}