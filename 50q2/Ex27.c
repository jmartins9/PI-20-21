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

LInt parte (LInt l){
    LInt y=NULL;
    LInt pt=l;
    LInt ant,aux;
    int i=0;
    while (pt!=NULL) {
        if (i%2!=0) {
            y=insereFim(pt->valor,y);
            ant->prox=pt->prox;
            aux=pt;
            ant=pt;
            pt=pt->prox;
            free(aux); 
            i++;
        }
        else {
            i++;
            ant=pt;
            pt=pt->prox;
        }
    }
    return y;
}



int main() {
  LInt l=NULL;
  l=newLInt(2,l);
  l=newLInt(1,l);
  l=newLInt(0,l);
  imprimeL(l);
  LInt x=parte(l);
  imprimeL(l);
  imprimeL(x);
  return 0;
}