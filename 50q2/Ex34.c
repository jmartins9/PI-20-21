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

int depth (ABin a, int x) {
   int nivel;
   int ne,nd;
   if (a==NULL) nivel=-1;
   else if (a->valor!=x) {
        ne=depth(a->esq,x);
        nd=depth(a->dir,x);

        if (ne!=-1 && nd!=-1) {
            if (ne<nd) nivel=1+ne;
            else nivel=1+nd;
        }
        else if (ne==-1 && nd!=-1) nivel=1+nd;
        else if (ne!=-1 && nd==-1) nivel=1+ne;
        else nivel=-1;
   }
   else if (a->valor==x) nivel=1;
   return nivel;
}


