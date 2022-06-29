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



void preorder (ABin a, LInt * l) {
    LInt new;
    if (a==NULL);
    else {
        preorder(a->dir,l);
        preorder(a->esq,l);
        new=(LInt) malloc(sizeof(struct lligada));
        new->valor=a->valor;
        new->prox=(*l);
        (*l)=new;
    }

}

void imprimeL (LInt l) {
     printf("LISTA:\n");
     while (l!=NULL) 
     {
        printf("->%d\n",l->valor);
        l=l->prox;
     }
}


int main() {
  ABin a=NULL;
  ABin e=newABin(1,NULL,NULL);
  ABin d=NULL;
  a=newABin(3,e,d);
  LInt l=NULL;
  preorder(a,&l);
  imprimeL(l);
  return 0;
}