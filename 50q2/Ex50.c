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

void dumpABin2 (ABin a){
    if (a){
        dumpABin2(a->esq);
        printf("%d ",a->valor);
        dumpABin2(a->dir);
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


int compL (LInt l) {
    int r=0;
    while (l!=NULL) {
        r++;
        l=l->prox;
    }
    return r;
}


void listToBTree (LInt l, ABin *a) {
    int comp = compL(l)/2;
  
    LInt tmp1=l;
    LInt ant=NULL;

    if (l!=NULL) {
        if (comp>0) {
            while (comp>0) {
                ant=tmp1;
                tmp1=tmp1->prox;
                comp--;
            }
            ABin aux=(ABin) malloc(sizeof(struct nodo));
            aux->valor=tmp1->valor;
            aux->esq=NULL;
            aux->dir=NULL;
            ant->prox=NULL;
            (*a)=aux;
            listToBTree(l,&((*a)->esq));
            listToBTree(tmp1->prox,&((*a)->dir));
        }
        else {
            ABin aux=(ABin) malloc(sizeof(struct nodo));
            aux->valor=tmp1->valor;
            aux->esq=NULL;
            aux->dir=NULL;
            (*a)=aux;
        }
    }
    else (*a)=NULL;
}

int main () {
    LInt z=NULL;
    z=newLInt(7,z);
    z=newLInt(6,z);
    z=newLInt(5,z);
    z=newLInt(4,z);
    z=newLInt(3,z);
    z=newLInt(2,z);
    z=newLInt(1,z);
    ABin a=NULL;
    listToBTree(z,&a);
}