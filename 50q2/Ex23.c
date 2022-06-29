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




LInt arrayToList (int v[], int N){
    int i;
    LInt pt=NULL;
    for (i=0;i<N;i++) {
         pt=insereFim(v[i],pt);
    } 
    return pt;
}


int main() {
  LInt l;
  int v[3]={1,2,3};
  l=arrayToList(v,3);
  imprimeL(l);
  return 0;
}