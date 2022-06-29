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


int drop (int n, LInt *l){
    int cont=0;
    LInt pt=(*l);
    LInt aux;
    while (pt!=NULL && n>0) {
           aux=pt;
           pt=pt->prox;
           free(aux);
           n--;
           cont++; 
    }
    (*l)=pt;
    return cont;
}

int main() {
  LInt l=NULL;
  l=newLInt(3,l);
  l=newLInt(2,l);
  l=newLInt(1,l);
  imprimeL(l);

  imprimeL(l);
  return 0;
}