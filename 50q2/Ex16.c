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

LInt cloneL (LInt l) {
      LInt r,cauda;
      if (l==NULL) r=NULL;
      else { cauda = cloneL (l->prox);
             r = newLInt (l->valor,cauda);
          } 
      return r;
}


LInt cloneL1 (LInt l) {
  LInt r,ult,*sitio;

  sitio=&r;

  while (l!=NULL) {
      *sitio = malloc(sizeof(struct lligada));
      (*sitio)->valor=l->valor;
      l=l->prox;
      sitio=&((*sitio)->prox);

  }
  *sitio=NULL;

  return r;
}

LInt cloneee (LInt l) {
    LInt nova = NULL; LInt guarda = NULL;
    LInt copia;

    while (l!=NULL) {
        copia = malloc (sizeof(struct lligada));
        copia->prox = NULL;
        copia->valor = l->valor;

        if (nova==NULL) {
            nova = copia;
            guarda = copia;
        }
        else {
            nova->prox = copia;
            nova = nova->prox;
        }
        
        l = l->prox;
    }

    return guarda;
}


int main() {
  LInt l=NULL;
  l=newLInt(3,l);
  l=newLInt(2,l);
  l=newLInt(1,l);
  LInt x= cloneee (l);
  imprimeL(x);
  imprimeL(l);
  return 0;
}