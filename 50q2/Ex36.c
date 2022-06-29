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


int pruneAB (ABin *a, int l) {
     int r=0;
     ABin aux;
     if ((*a)==NULL);
     else if (l>0) {
        r=pruneAB(&((*a)->esq),l-1);
        r+=pruneAB(&((*a)->dir),l-1);
     }
     else {
        aux=(*a);
        (*a)=NULL;
        r=freeAB(aux);
     }
     return r;
}