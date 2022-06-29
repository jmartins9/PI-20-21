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

int removeOneOrd (LInt *l, int x){
    LInt pt;
    int r=1;
    while ((*l)!=NULL && (*l)->valor!=x) {
           l=&((*l)->prox);
    } 

    if ((*l)!=NULL && (*l)->valor==x) {
        r=0;
        pt=*l;
        (*l)=(*l)->prox;
        free(pt);
    }

    return r;
}




int main() {
  LInt l=NULL;
  l=newLInt(2,l);
  l=newLInt(1,l);
  imprimeL(l);
  imprimeL(l);
  return 0;
}