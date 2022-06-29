#include <stdio.h>

/* Defina uma função 
   int minInd (int v[], int n) 
   que, dado um vector v com n inteiros, retorna o 
   índice do menor elemento do vector.
*/

int minInd (int v[], int n) {
   int i;
   int minind=0;
   int guardamin=v[0];
   for (i=1;i<n;i++) {
    if (v[i]<guardamin) {
         guardamin=v[i];
         minind=i;
    }
   }
   return minind;
}