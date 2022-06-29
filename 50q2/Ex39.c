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

int nivelV (ABin a, int n, int v[]) {
    int r=0;
    if (a==NULL || n<=0);
    else if (n>1) {
        r=nivelV(a->esq,n-1,v);
        r+=nivelV(a->dir,n-1,v+r);
    } 
    else {
        v[r++]=a->valor;
    }
    return r;
}