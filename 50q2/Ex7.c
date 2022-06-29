#include <stdio.h>
#include <stdlib.h>

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


void imprimeL (LInt l) {
     printf("LISTA:\n");
     while (l!=NULL) 
     {
        printf("->%d\n",l->valor);
        l=l->prox;
     }
}

void insertOrd (LInt *l, int x){
     LInt new = (LInt) malloc (sizeof(struct lligada));
     new->valor=x;

     while ((*l)!=NULL && (*l)->valor<x) {
           l=&((*l)->prox);
     }
     new->prox=(*l);
     (*l)=new;
}


void merge (LInt *r, LInt l1, LInt l2){
    int x;
    (*r)=l1;
    while (l2!=NULL) {
        x=l2->valor;
        insertOrd(r,x);
        l2=l2->prox;
    }
}



int main() {
  LInt l=NULL;
  l=newLInt(2,l);
  l=newLInt(1,l);
  imprimeL(l);
  imprimeL(l);
  return 0;
}