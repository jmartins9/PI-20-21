#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
1. Defina uma função int paresImpares (int v[], int N) que organiza o array v de forma a
que apareçam primeiro os elementos pares e depois os ímpares. A função deverá retornar o
número de números pares do array. Serão valorizadas as soluções que não usem um array auxiliar.
*/

void printArray (int v[], int N) {
    int i;
    for (i=0;i<N;i++) {
        printf("%d ",v[i]);
    }
    printf("\n");
}



void swap (int v[],int i, int j) {
    int guarda = v[i];
    v[i] = v[j];
    v[j] = guarda;
}



int paresImpares (int v[], int N) {
    int i = 0;
    int j = N-1;

    while (i<j) {
        if (v[i]%2!=0 && v[j]%2==0) {
            swap(v,i,j);
            i++;
            j--;
        }
        else if (v[i]%2==0) i++;
        else if (v[j]%2!=0) j--;
    }
    
    return i;
}

/*
2. Defina uma função void merge (LInt *r, LInt a, LInt b) que junta duas listas
ordenadas (a e b) numa única lista ordenada (em *r). A função não deve alocar nem libertar
memória, mas apenas reorganizar os nodos das listas.
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


void imprimeL (LInt l) {
     printf("LISTA:\n");
     while (l!=NULL) 
     {
        printf("->%d\n",l->valor);
        l=l->prox;
     }
}


void merge (LInt *r, LInt a, LInt b) {
    LInt start = NULL;

    while (a!=NULL && b!=NULL) {
        if (a->valor<b->valor) {
            if (start==NULL) {
                (*r) = a;
                start = a;
            }
            else {
                start->prox = a;
                start = start->prox;
            }
            a = a->prox;
        }
        else {
            if (start==NULL) {
                (*r) = b;
                start = b;
            }
            else {
                start->prox = b;
                start = start->prox;
            }
            b = b->prox;
        }
    }

    while (a!=NULL) {
        if (start==NULL) {
            (*r) = a;
            start = a;
        }
        else {
            start->prox = a;
            start = start->prox;
        }
        a = a->prox;
    }
    
    while (b!=NULL) {
        if (start==NULL) {
            (*r) = b;
            start = b;
        }
        else {
            start->prox = b;
            start = start->prox;
        }
        b = b->prox;
    }

}


/*
3. Um quadrado latino é uma matriz de dimensão N x N onde cada linha e cada coluna tem todos os
números de 1 até N. Implemente a função void latino (int N, int m[N][N]) por forma a
que preencha a matriz m com um quadrado latino de dimensão N. Um exemplo de um quadrado
latino de dimensão 3 é
    1 2 3
    2 3 1
    3 1 2
*/

void latino (int N, int m[N][N]) {
    int j,i,ia;

    for (i=0;i<N;i++) {
        ia = i;
        for (j=0;j<N;j++) {
            if (i==0) {
                m[i][j] = j+1;
            }
            else {
                m[i][j] = m[0][ia++];
                if (ia==N) ia = 0;
            }
        }
    }

}


void printfMatriz (int N, int m[N][N]) {

    int i,j;

    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

} 

/*

Numa árvore binária de procura podemos também guardar em cada nodo o apontador para o
respectivo pai. Essas árvores podem ser definidas da seguinte forma:



Defina a função ABin next (ABin a) que, dado um apontador para um dos nodos da árvore,
devolve o apontador para o nodo que contém o próximo valor numa travessia inorder (ou NULL se
não existir).


*/

typedef struct nodo {
    int valor;
    struct nodo *pai, *esq, *dir;
} *ABin;

/*
 if (a->dir!=NULL) b = a->dir;
        else if (a->pai!=NULL && a->pai->esq==a) b = a->pai;
        else {
            ABin ant = NULL;
            while (a->pai!=NULL) {
                ant = a;
                a = a->pai;
            }

            if (ant!=NULL && a->esq==ant) b = a;  
        }





        if (a->pai==NULL) b = findMenor(a->dir);
        else if (a->pai->esq==a) b = a->pai;
        else {
            while (a->pai!=NULL) {
                a = a->pai;
            }

            b = findMenor(a->dir);
        }
*/

ABin findMenor (ABin a) {
    ABin b = NULL;
    if (a!=NULL) {
        if (a->esq==NULL) b = a;
        else b = findMenor(a->esq);
    }
    return b;
}


ABin next (ABin a) {
    ABin b = NULL;
    if (a!=NULL) {
        if (a->pai==NULL) b = findMenor(a->dir);
        else if (a->dir!=NULL) b = findMenor(a->dir);
        else if (a->pai->esq==a) b = a->pai;
        else {
            while (a->pai!=NULL && a->pai->dir==a){
                a = a->pai;
            } 
            b = a->pai;
        }           
    }

    return b;
}

/*
De forma a calcular a palavra mais frequente de um texto, assuma que as ocorrências de cada
palavra são armazenadas numa árvore de procura, ordenada (lexicograficamente) pela palavra.



Defina uma função int acrescentaPal (Palavras *p, char *pal) que acrescenta uma
nova ocorrência da palavra pal. Se pal não existir em *p, deve ser acrescentada; no outro caso
deve ser apenas atualizado o número de ocorrências. Além disso, a função deve garantir que as
palavras mais frequentes aparecem num nível mais elevado, em particular, a palavra mais
frequente aparecerá sempre como raíz da árvore. Para atingir este objectivo, use as funções void
rodaDireita (Palavras *a) e void rodaEsquerda (Palavras *a) estudadas na Ficha
10 e que promovem um elemento um nível na árvore.

*/

typedef struct palavras {
    char *palavra;
    int nOcorr;
    struct palavras *esq, *dir;
} *Palavras;


void rodaDireita (Palavras *a) {
    Palavras b = (*a)->esq;
    (*a)->esq = b->dir;
    b->dir = (*a);
    (*a) = b;
}

void rodaEsquerda (Palavras *a) {
    Palavras b = (*a)->dir;
    (*a)->dir = b->esq;
    b->esq = (*a);
    (*a) = b;
}


int acrescentaPal (Palavras *p, char *pal)  {
    int r = 0;
    int comp;

    if ((*p)==NULL) {
        Palavras nova = malloc(sizeof(struct palavras));
        nova->dir = NULL;
        nova->esq = NULL;
        nova->nOcorr = 1;
        nova->palavra = strdup(pal);
        (*p) = nova;
    }
    else {
        comp = strcmp(pal,(*p)->palavra);
        if (comp==0) {
            (*p)->nOcorr++;
            r = 1;
        }
        else if (comp>0) {
            r = acrescentaPal(&((*p)->dir),pal);
            rodaEsquerda(p);
        }
        else if (comp<0) {
            r = acrescentaPal(&((*p)->esq),pal);
            rodaDireita(p);
        }
    }

    return r;
}


int main () {

    /*

    int v[10] = {1,1,1,1,5,1,7,1,9,1};

    printf("%d\n",paresImpares(v,10));

    printArray(v,10);

    */ 

    /*
    LInt l = newLInt(20,NULL);
    l = newLInt(18,l);
    l = newLInt(17,l);
    l = newLInt(15,l);
    l = newLInt(10,l);
    l = newLInt(6,l);
    l = newLInt(3,l);
    l = newLInt(1,l);
    
    
    LInt L = newLInt(9,NULL);
    L = newLInt(8,L);
    L = newLInt(4,L);
    L = newLInt(3,L);

    LInt r = NULL;
    merge(&r,l,L);

    imprimeL(r);
    */
    /*
    int m[10][10];

    latino(10,m);

    printfMatriz(10,m);

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


    printf("%d\n",next(a)->valor);

}


