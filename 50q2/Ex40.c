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

int dumpAbin (ABin a, int v[], int N) {
    int r=0;
    if (a==NULL || r>=N); 
    else {
        r=dumpAbin(a->esq,v,N);
        if (r<N) v[r++]=a->valor;
        r+=dumpAbin(a->dir,v+r,N-r);
    }
    return r;
}
