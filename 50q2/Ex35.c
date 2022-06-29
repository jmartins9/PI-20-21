#include <stdio.h>
#include <stdlib.h>


typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

typedef struct nodo {
	int valor;
	struct nodo *esq, *dir;
} *ABin;

int freeAB (ABin a) {
    int r;
    ABin tmp;
    if (a==NULL) r=0;
    else {
        tmp=a;
        r=1+freeAB(a->esq);
        r+=freeAB(a->dir);      
        free(tmp);
    }
    return r;
}

