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


void remreps (LInt l){
    LInt pt=l;
    LInt ant=pt;
    LInt aux;
    if (pt!=NULL) {
        ant=pt;
        pt=pt->prox;
    }
    while (pt!=NULL) {
        if (ant->valor==pt->valor) {
            ant->prox=pt->prox;
            aux=pt;
            pt=pt->prox;
            free(aux);
        }
        else {
            ant=pt;
            pt=pt->prox;
        }
    }    
}

int main() {
  LInt l=NULL;
  l=newLInt(3,l);
  l=newLInt(1,l);
  l=newLInt(1,l);
  imprimeL(l);
  remreps(l);
  imprimeL(l);
  return 0;
}