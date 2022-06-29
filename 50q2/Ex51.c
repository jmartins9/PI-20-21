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


int comparaMenor (int x,ABin a) {
    int r=0;
    if (a==NULL) r=1;
    else if (x<a->valor) {
        r=comparaMenor(x,a->esq);
        if (r) r=comparaMenor(x,a->dir);
    }
    return r;
}

int comparaMaior (int x,ABin a) {
    int r=0;
    if (a==NULL) r=1;
    else if (x>a->valor) {
        r=comparaMaior(x,a->esq);
        if (r) r=comparaMaior(x,a->dir);
    }
    return r;
}


// falta função que verifica se o numero é menor ou maior que os outros todos de um lado

int deProcura (ABin a) {
    int r=1;
    if (a==NULL);
    else {
        if (a->esq!=NULL) {
            if (comparaMaior(a->valor,a->esq)) r=deProcura(a->esq);  
            else r=0;
        }
        if (a->dir!=NULL && r==1) {
            if (comparaMenor(a->valor,a->dir)) r=deProcura(a->dir);
            else r=0;
        }
    }
    return r;
}