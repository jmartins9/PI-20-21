#include <stdio.h>

int main () {
int t = 1%-2;
printf("%d",t);
}

/*

Em C, existe  uma abreviatura para (*a).b, em que a é um endereço de uma struct que tem um campo chamado b
Em vez disto escrevemos a->b 

typedef struct stack {
    int valores [100];
    int quantos;
} STACK,*SStack;


void push (int x,STACK *s) {
    s->valores[s->quantos++] = x;
}

void pop (STACK *s) {
    s->quantos--;
}


int top (STACK *s) {
    return (s->valores[s->quantos-1]);
}

int empty (STACK *s) {
    return (s->quantos==0);
}

int main () {
    STACK s1;
    int aaa;
    s1.quantos=0;
    s1=push (3,&s1);
    aaa = top (&s1);
    return 0;
}



define dois tipos 
STACK que é o mesmo que struct stack
SStack que é endereço de STACK

Agora em vez de STACK *s , escrevemos SStack s 

Heap - memória não automática 

#include <stdlib.h> --- biblioteca para este tipo de memória 

typedef struct stack {
    int N;
    int *valores; // valores é um array de tamanho n
    int quantos;
} STACK,*SStack;

void initStack (int tamanho,SStack s) {
    s->valores = (int*) malloc(tamanho *sizeof(int));
    s->N=tamanho;
}

int main () {
    STACK s1;
    int aaa;
    initStack (10,&s1);
    s1.quantos=0;
    s1=push (3,&s1);
    aaa = top (&s1);
    free(s.valores);
    return 0;
}


*/