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

int take (int n, LInt *l){
    int comp=0;
    while ((*l)!=NULL && n>0) {
        l=&((*l)->prox);
        n--;
        comp++;
    }
    if ((*l)!=NULL) {
        LInt tmp=(*l)->prox;
        (*l)=NULL;
        l=&tmp;
        LInt aux;
        while ((*l)!=NULL) {
              aux=(*l);
              l=&((*l)->prox);
              free(aux);
        }
    }
    return comp;
}

int main() {
  LInt l=NULL;
  l=newLInt(3,l);
  l=newLInt(2,l);
  l=newLInt(1,l);
  imprimeL(l);
  take(2,&l);
  imprimeL(l);
  return 0;
}