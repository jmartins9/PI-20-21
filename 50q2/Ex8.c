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


void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
     while (l!=NULL) {
         if (l->valor<x) {
             *mx=insereFim(l->valor,*mx);
         }
         else {
             *Mx=insereFim(l->valor,*Mx);
         }
         l=l->prox;
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