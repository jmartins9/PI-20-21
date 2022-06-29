#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

int main () {
    double soma = 1 + 2.3 ;
    printf ("%f",soma);
}

struct s {
    int sp;
    int valores [60];
};

/*

struct s {
    int sp;
    int valores [60];
};

int x[10],y[10];
struct s a;
struct s b;

x=y; //está errado 
//a=b; // está correto 

//passagem como argumento 

int f(int v[],int N);

int main () {
    int x [400];
    f(x,400);
     // consequencias : nao é feita uma cópia do array , quaisquer alteraçoes feitas no array pela função 
}  
   
   int g ( struct s a)
   g (xxxx) 
     é feita uma cópia do argumento 
     quaisquer alterações feitas à stuct pela função não são visíveis do exterior

*/

// ------------- Exemplo : stack de inteiros -----------------------


/*
push acrescentar elemento 
pop retirara elemento 
top qual o proximo elemento a ser retirado 
empty saber se a stack está vazia 

int A; A é uma variável do tipo int
typedef int B; B um tipo equivalente a int
B x; x é uma variável do tipo B. i.e.,int 


typedef struct stack {
    int valores [100];
    int quantos;
} STACK;

STACK push (int x, STACK s) {
    s.valores[s.quantos]=x;
    s.quantos++;
    return s;
}

STACK pop (STACK s) {
    s.quantos;

}

int top (STACK s) {
return (s.valores [s.quantos -1]);
}

int empty (STACK s) {
    return (s.quantos==0);
}





*/