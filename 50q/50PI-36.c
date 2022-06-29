#include <stdio.h>

/* a função 
   int comuns (int a[], int na, int b[], int nb) 
   que calcula quantos elementos do vector a (com na elementos) 
   ocorrem no vector b (com nb elementos). 
   Assuma que os vectores a e b não estão ordenados 
   e defina a função sem alterar os vectores.
*/
int ncomun (int n,int b[],int nb) {
    int i,r=0;
    for (i=0;i<nb;i++) {
        if (b[i]==n) r=1;
    }
    return r;
}

int comuns (int a[], int na, int b[], int nb){
    int i,r=0;
    for (i=0;i<na;i++) {
       r = r + ncomun(a[i],b,nb);
    }
    return r;
}

