#include <stdio.h>

/* a uma função 
   int elimRep (int v[], int n) 
   que recebe um vector v com n inteiros e elimina 
   as repetições. 
   A função deverá retornar o número de elementos 
   do vector resultante.
   Por exemplo, se o vector v contiver nas suas 
   primeiras 10 posições os números
   {1, 2, 3, 2, 1, 4, 2, 4, 5, 4}
   a invocação elimRep (v,10) deverá retornar 5 e 
   colocar nas primeiras 5 posições do vector os 
   elementos {1,2,3,4,5}.
*/

int pertence (int v[],int x,int N) {
    int i,r=0;
    for (i=0;i<N;i++) {
        if (v[i]==x) r=1;
    }
    return r;
}

int elimRep (int v[], int N) {
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