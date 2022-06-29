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


LInt parteAmeio (LInt *l){
    int tamanho=0;
    LInt aux=(*l);
    while (aux!=NULL) {
        aux=aux->prox;
        tamanho++;
    }
    tamanho=tamanho/2;


    LInt metade=NULL;
    LInt metade2=NULL;
    LInt pt=(*l);

    while (pt!=NULL) {
          if (tamanho>0) {
             metade=insereFim(pt->valor,metade);
             pt=pt->prox;
          }
          else {
             metade2=insereFim(pt->valor,metade2);
             pt=pt->prox;
          }
          tamanho--;
    }

    (*l)=metade2;
    
    return metade;
}


int main() {
  LInt l=NULL;
  l=newLInt(3,l);
  l=newLInt(2,l);
  l=newLInt(1,l);
  imprimeL(l);
  LInt x;
  x=parteAmeio(&l);
  imprimeL(x);
  imprimeL(l);
  return 0;
}