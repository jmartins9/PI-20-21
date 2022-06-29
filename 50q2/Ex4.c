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

LInt reverseL (LInt l){
    LInt new=NULL;
    if (l==NULL) new = l;
    while (l!=NULL) {
        new = newLInt (l->valor,new);
        l=l->prox;
    }
    free(l);
    return new;
}

LInt reverseL (LInt l){
    LInt ant=NULL,prox;
    if (l!=NULL) {
        prox=l->prox;
        l->prox=NULL;
        ant=l;
        l=prox;
    }
    while (l!=NULL) {
           prox=l->prox;
           l->prox=ant;
           ant=l;
           l=prox;  
           
    }
    l=ant;
    return l;
}





void imprimeL (LInt l) {
     printf("LISTA:\n");
     while (l!=NULL) 
     {
        printf("->%d\n",l->valor);
        l=l->prox;
     }
}


int main() {
  LInt l=NULL;
  l=newLInt(2,l);
  l=newLInt(1,l);
  imprimeL(l);
  l = reverseL(l);
  imprimeL(l);
  return 0;
}