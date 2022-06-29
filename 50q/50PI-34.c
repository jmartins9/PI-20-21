#include <stdio.h>

/* a uma função 
   int elimRepOrd (int v[], int n) que recebe 
   um vector v com n inteiros ordenado por ordem 
   crescente e elimina as repetições. 
   A função deverá retornar o número de elementos 
   do vector resultante.
*/ 

int pertence (int v[],int x,int N) {
    int i,r=0;
    for (i=0;i<N;i++) {
        if (v[i]==x) r=1;
    }
    return r;
}

int elimRepOrd (int v[], int N) {
    int r,ind,wr;
    ind=wr=0;
    v[wr++]=v[ind++];
    r=1;
    for(;ind<N;ind++) {
        if (pertence(v,v[ind],r)==0) {
            v[wr]=v[ind];
            wr++;
            r++;
        }
    }   
    return r;
}