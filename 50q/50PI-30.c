#include <stdio.h>

/* Defina uma função 
   int menosFreq (int v[], int N) 
   que recebe um vector v com N elementos 
   ordenado por ordem crescente e retorna 
   o menos frequente dos elementos do vector.
   Se houver mais do que um elemento nessas 
   condições deve retornar o que começa por 
   aparecer no índice mais baixo.
*/
int menosFreq (int v[], int N){
    int r,i,conta,minconta,n;
    i=0;
    minconta=0;
    n=v[i];
    r=v[i];
    while (n==v[i]) {
        minconta++;
        i++;
    }
    for (;i<N;) {
       n=v[i];
       conta=0;
       while (n==v[i]) {
           conta++;
           i++;
       }
       if (conta<minconta) {r=v[i-1];minconta=conta;}
    }
    return r;
}

int main () {
    int s[30]={2,2,2,3,3,3,4,4,5,5,5,5,5,5,5,6,6,6,6,6};
    menosFreq(s,20);
}