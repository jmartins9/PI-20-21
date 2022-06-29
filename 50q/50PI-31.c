#include <stdio.h>

/* a função 
   int maisFreq (int v[], int N)
   que recebe um vector v com N elementos 
   ordenado por ordem crescente e retorna 
   o mais frequente dos elementos do vector.
   Se houver mais do que um elemento nessas 
   condições deve retornar o que começa por 
   aparecer no índice mais baixo.
*/

int contador (int v[],int ind,int N) {
    int r=1; 
    while (v[ind]==v[ind+1] && ind<N) {
        ind++;
        r++;
    }
    return r;
}

int maisFreq (int v[], int N){
    int r,ind,conta,maxconta;
    ind=conta=maxconta=0;
    r=v[ind];
    maxconta=contador(v,ind,N);
    ind=ind+maxconta;
    while (ind<N) {
        conta=contador(v,ind,N);
        ind=ind+conta;
        if (maxconta < conta) {
            maxconta = conta;
            r=v[ind-1];
        }
    }
    return r;
}

