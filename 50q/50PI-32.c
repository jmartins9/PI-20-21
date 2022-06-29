#include <stdio.h>

/* a função 
   int maxCresc (int v[], int N)
   que calcula o comprimento da maior sequência 
   crescente de elementos consecutivos num vector 
   v com N elementos.
   Por exemplo, se o vector contiver 10 elementos 
   pela seguinte ordem:
   {1, 2, 3, 2, 1, 4, 10, 12, 5, 4}, 
   a função deverá retornar 4, correspondendo ao 
   tamanho da sequência {1, 4, 10, 12}.
*/

int contador (int v[],int ind,int N) {
    int r=1; 
    while (v[ind]<=v[ind+1] && ind<N) {
        ind++;
        r++;
    }
    return r;
}


int maxCresc (int v[], int N) {
    int r,ind,tamanho,tamanhomax;
    r=ind=tamanho=tamanhomax=0;
    r=tamanhomax=contador(v,ind,N);
    ind=ind+tamanhomax;
    while (ind<N) {
        tamanho=contador(v,ind,N);
        ind=ind+tamanho;
        if (tamanho>tamanhomax) {
            tamanhomax=tamanho;
            r=tamanho;
        } 
    }
    return r;
}