#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Relembre a seguinte função que calcula um somatório. Modifique-a por forma a que, para um n
arbitrário, em vez da soma, devolva a 100ª menor parcela do somatório ou -1 caso haja menos do
que 100 parcelas
*/

void insere (int v[], int x, int N) {
    int i,j;
    for (i=0;i<N && x>=v[i];i++);

    for (j=N-1;j>=i+1;j--) {
        v[j] = v[j-1];
    }
    
    if (i<N) v[i]=x;
}

int sumhtpo (int n) {
    int v[3];
    int N = 0;
    int r = 0;
    while (n != 1) {
        if (N<3) ++N;
        insere(v,n,N);
        r += n; 
        if (n%2 == 0) n = n/2; 
        else n = 1+(3*n);  
    }

    if (N==3) r = v[N-1];
    else r = -1;
    return r;
}

/*
A moda de um (multi-)conjunto é o valor que ocorre mais frequentemente nesse conjunto. Se
houver mais do que um valor com a mesma frequência mais elevada, o conjunto diz-se multimodal.
Implemente uma função int moda(int v[], int N, int *m) por forma a calcular (em *m) a
moda de um conjunto de N inteiros armazenado no array v, devolvendo a respectiva frequência. Se
não for possível determinar univocamente a moda, quando o conjunto é vazio ou multimodal, deve
devolver 0.
*/

int numVezes (int v[], int N, int x) {
    int r = 0;
    int i;
    for (i=0;i<N;i++) {
        if (v[i]==x) r++;
    }
    return r;
}


int moda(int v[], int N, int *m) {
    int r=0;
    int i;
    int multi = 0;
    int moda;
    int freq;
    int aux;

    if (N>0) {

        moda =  v[i];
        freq = numVezes(v,N,v[i]);

        for (i=1;i<N;i++) { 
            if (v[i]!=moda) {
                aux = numVezes(v,N,v[i]);
                if (aux>freq) {
                    freq = aux;
                    moda = v[i];
                    multi = 0;
                }
                else if (aux==freq) multi=1;
            }
        }

        (*m) = moda;
        r = freq;

    }

    if (multi==1) {
        (*m) = moda;
        r = 0;
    }

    return r; 

}


/*
Defina uma função int procura (LInt *l, int x) que procura um inteiro numa lista de
inteiros. A função deve retornar 0 se o elemento não existir. Se o elemento existir, a função deve
retornar 1 e passar esse elemento para o início da lista.
*/

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

int procura (LInt *l, int x) {
    int r = 0;

    LInt start = (*l);
    LInt ant = NULL;

    while (start!=NULL && !r) {
        if (start->valor==x) r = 1;
        else {
            ant = start;
            start = start->prox;
        }
    }

    if (ant!=NULL && r) {
        ant->prox = start->prox;
        
        start->prox = (*l);
        (*l) = start;
    }

    return r;
}

void imprimeL (LInt l) {
     printf("LISTA:\n");
     while (l!=NULL) 
     {
        printf("->%d\n",l->valor);
        l=l->prox;
     }
}




/*

Numa árvore binária podemos também guardar em cada nodo o apontador para o respectivo pai.
Essas árvores podem ser definidas da seguinte forma:



Defina uma função int freeAB(ABin a) que dado um apontador para a raiz da árvore liberta todo
o espaço de memória ocupado pela mesma, retornando o número de nodos libertados.

*/

typedef struct nodo {
    int valor;
    struct nodo *pai, *esq, *dir;
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



int freeAB(ABin a) {
    int r = 0;

    if (a!=NULL) {
        r += freeAB(a->esq);
        r += freeAB(a->dir);
        free(a);
        r++;
    }

    return r;
}


/*

Defina uma função  que dado um apontador para um nodo qualquer de
uma árvore binária com pais (tal como definida na questão anterior) imprime qual o caminho a
seguir para ir da raiz até esse nodo (uma sequência de direções, “esq” ou “dir”, uma por linha). 

*/


void caminho(ABin a) {

    if (a!=NULL && a->pai!=NULL) {
            caminho(a->pai);
            if (a->pai->esq==a) printf("esq\n");
            else printf("dir\n");
    }

}





int main () {
/*
    printf("%d\n", sumhtpo(16));

    int N = 10;
    int v[10] = {1,1,1,1,1,6,7,7,7,10};

    int m;
    int r = moda(v,10,&m);

    printf("\n%d %d\n",r,m);

    LInt l = NULL;
    l = newLInt(1,l);
    l = newLInt(4,l);
    l = newLInt(7,l);
    l = newLInt(3,l);
    imprimeL(l);

    printf("\n%d\n", procura(&l,1));

    imprimeL(l);
*/

    ABin e1 = malloc (sizeof(struct nodo));
    e1->valor = 20;
    e1->esq = NULL;
    e1->dir = NULL;

    ABin d1 = malloc (sizeof(struct nodo));
    d1->valor = 30;
    d1->esq = NULL;
    d1->dir = NULL;
 
    ABin e2 = malloc (sizeof(struct nodo));
    e2->valor = 40;
    e2->esq = NULL;
    e2->dir = NULL;

    ABin d2 = malloc (sizeof(struct nodo));
    d2->valor = 50;
    d2->esq = NULL;
    d2->dir = NULL;





    ABin e = malloc (sizeof(struct nodo));
    e->valor = 10;
    e->esq = e1;
    e->dir = d1;

    e1->pai = e;
    d1->pai = e;

    ABin d = malloc (sizeof(struct nodo));
    d->valor = 5;
    d->esq = e2;
    d->dir = d2;

    e2->pai = d;
    d2->pai = d;

    ABin a = malloc (sizeof(struct nodo));
    a->pai = NULL;
    a->valor = 15;
    a->esq = e;
    a->dir = d;

    e->pai = a;
    d->pai = a;


    printf("      %d\n    %d  %d  \n %d %d %d %d\n\n", a->valor,a->esq->valor,a->dir->valor,a->esq->esq->valor,a->esq->dir->valor,a->dir->esq->valor,a->dir->dir->valor);

    caminho(e1);

}