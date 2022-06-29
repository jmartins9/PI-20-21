#include <stdio.h>
#include <string.h>

/* a função 
   void merge (int r [], int a[], int b[], int na, int nb) 
   que, dados vectores ordenados a (com na elementos) e 
   b (com nb elementos), preenche o vector r (com na+nb 
   elementos) com os elementos de a e b ordenados.
*/
void merge (int r [], int a[], int b[], int na, int nb){
     int ia,ib,ir;
     for(ia=ib=ir=0;ia<na && ib<nb;) {
         if (a[ia]<=b[ib]) {r[ir]=a[ia];ir++;ia++;}
         else {r[ir]=b[ib];ib++;ir++;}
     }     
     for (;ib<nb;ib++) {
         r[ir]=b[ib];
         ir++;
     }
     for (;ia<na;ia++) {
         r[ir]=a[ia];
         ir++;
     }
     r[ir]='\0';
     return;
}