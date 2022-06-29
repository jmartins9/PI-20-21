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

int pertenceL (LInt l,int x) {
    int r=0;
    while (l!=NULL && r==0) {
        if (l->valor==x) r=1;
        l=l->prox;
    }
    return r;
}

int removeDups (LInt *l){
    int cont=0;
    LInt nova=NULL;
    LInt pt=(*l);
    while (pt!=NULL) {
          if (!pertenceL(nova,pt->valor)) {
              cont++;
              nova=insereFim(pt->valor,nova);
          }
          pt=pt->prox;
    }
    (*l)=nova;
    return cont;
}

int main() {
  LInt l=NULL;
  l=newLInt(3,l);
  l=newLInt(2,l);
  l=newLInt(1,l);
  imprimeL(l);
  int x;

  imprimeL(l);
  printf("%d\n",x);
  return 0;
}