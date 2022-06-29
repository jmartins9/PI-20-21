#include <stdio.h>

/* a uma função 
   int crescente (int a[], int i, int j) 
   que testa se os elementos do vector a, entre as 
   posições i e j (inclusivé) estão ordenados por 
   ordem crescente. 
   A função deve retornar 1 ou 0 consoante o 
   vector esteja ou não ordenado.
*/
   int crescente (int a[], int i, int j){
       int r=1;
       for (;i<j && r!=0;i++) {
           if (a[i]<=a[i+1]);
           else r=0;
       }
       return r;
   }