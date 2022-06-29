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


int removeMaiorL (LInt *l){
    LInt nova=NULL;
    LInt pt=(*l);
    int maior;
    maior=pt->valor;
    while (pt!=NULL) {
          if (pt->valor>maior) maior=pt->valor;
          pt=pt->prox;
    }
    LInt pt1=(*l);
    int aux=0;
    while (pt1!=NULL) { 
          if (pt1->valor!=maior) nova=insereFim(pt1->valor,nova);
          else if (pt1->valor==maior && aux==0) aux=1;
          else if (pt1->valor==maior && aux==1) nova=insereFim(pt1->valor,nova);
          pt1=pt1->prox;
    }
    (*l)=nova;
    return maior;
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