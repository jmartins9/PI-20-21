#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

void freeL (LInt l) {
    while (l!=NULL) {
           free(l);
           l=l->prox;
    }          
}
