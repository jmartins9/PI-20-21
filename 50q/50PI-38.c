#include <stdio.h>

/* a função 
   void somasAc (int v[], int Ac [], int N)
   que preenche o vector Ac com as somas acumuladas 
   do vector v. 
   Por exemplo, o elemento na posição Ac[3] deve 
   ser calculado como v[0]+v[1]+v[2]+v[3].
*/

int soma (int iv,int v[]) {
    int i;
    int soma=0;
    for (i=0;i<=iv;i++) {
        soma = soma + v[i];
    }
    return soma;
}

void somasAc (int v[], int Ac [], int N){
   int iv;
   for (iv=0;iv<N;iv++) {
       Ac[iv]=soma(iv,v);
   }
}
   