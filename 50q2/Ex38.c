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


LInt insereFim (int x,LInt l) {
     LInt pt=l,ant;
     
     LInt new= (LInt) malloc(sizeof(struct lligada));
     new->valor=x;
     new->prox=NULL;
     
     if (l!=NULL) {
        while (l!=NULL) {
            ant=l;
            l=l->prox;
        }
        ant->prox=new;
     }
     else pt=new;
     return pt;
}

LInt concatena (LInt a,LInt b) {
     LInt pt=NULL;

     while (a!=NULL) {
         pt=insereFim(a->valor,pt);
         a=a->prox;
     }
     while (b!=NULL) {
         pt=insereFim(b->valor,pt);
         b=b->prox;
     }
     return pt;
}

LInt nivelL (ABin a, int n) {
    LInt pt=NULL;
    if (a==NULL || n<=0);
    else if (n>1) {
        pt=concatena(pt,nivelL(a->esq,n-1));
        pt=concatena(pt,nivelL(a->dir,n-1));
    } 
    else {
        pt=insereFim(a->valor,pt);   
    }
    return pt;
}
