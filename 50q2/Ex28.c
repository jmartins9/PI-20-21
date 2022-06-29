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

int altura (ABin a){
    int alt;
    if (a==NULL) alt=0;
    else { 
        int altesq = 1 + altura(a->esq);
        int altdir = 1 + altura(a->dir);
        if (altesq>altdir) alt=altesq;
        else alt=altdir;
    }
	return alt;
}

