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

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;


LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}



void posorder (ABin a, LInt * l) {
    LInt new;
    if (a==NULL);
    else {
        new=(LInt) malloc(sizeof(struct lligada));
        new->valor=a->valor;
        new->prox=(*l);
        (*l)=new;
        posorder(a->dir,l);
        posorder(a->esq,l);
    }
}
