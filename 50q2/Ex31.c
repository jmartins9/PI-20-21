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



/* Defina a função "LInt* inorder (ABin , LInt *)" que cria uma lista ligada
 de inteiros a partir de uma travessia "in-order" de uma árvore binária. */
void inorder (ABin a, LInt * l) {
    LInt new;
    if (a==NULL);
    else {
        inorder(a->dir,l);
        new=(LInt) malloc(sizeof(struct lligada));
        new->valor=a->valor;
        new->prox=(*l);
        (*l)=new;
        inorder(a->esq,l);
    }
}