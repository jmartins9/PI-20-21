#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

ABin newABin (int r, ABin e, ABin d){
	ABin new = (ABin) malloc (sizeof (struct nodo));

	if (new!=NULL){
		new->valor = r;
		new->esq   = e;
		new->dir   = d;
	}
	return new;
}

/* Defina uma função "void mirror (ABin *)" que inverte uma árvore (sem criar
 uma nova árvore). */
void mirror (ABin *a) {
   ABin pt=(*a);
   if (pt==NULL);
   else {
	   ABin aux1=pt->esq;
       ABin aux2=pt->dir;
	   pt->esq=aux2;
	   pt->dir=aux1;
	   mirror(&(pt->esq));
	   mirror(&(pt->dir));
   }
}

int main() {
  ABin a=NULL;
  a=newABin(3,NULL,NULL);


  return 0;
}