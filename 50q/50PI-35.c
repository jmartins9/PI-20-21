#include <stdio.h>
/* a uma função 
   int comunsOrd (int a[], int na, int b[], int nb)
   que calcula quantos elementos os vectores 
   a (com na elementos) e b (com nb elementos) 
   têm em comum.
   Assuma que os vectores a e b estão ordenados por 
   ordem crescente.
*/

//--------------------------------------------------------------

int elimina_ord1 (int bruh[], int n, int N){
    int i, j, contador = 0;
    for (i = n+1; i < N; i++){
        if (bruh[i] > bruh[n]) return (N-contador);
        if (bruh[n] == bruh[i]){
            for(j = n; j < N-1; j++){
                bruh[j] = bruh[j+1];
            }
            contador++;
        }
    }
    return (N-contador);
}

int elimRepOrd1 (int v[], int N) {
       int i, j;
       N = elimina_ord1 (v, 0, N);
       for (i = 0; i < N; i++){
           for (j = 0; j < N; j++){
               N = elimina_ord1 (v, j, N);
           }
       }
       return N;
   }


int tem_repetido1 (int v[], int nv){   
    int i, r = 0;
    for (i = 0; i < nv; i++){ 
        if (v[i] == v[i+1]) return r = 1;
        }
      return r; 
    }


int comunsOrd1 (int a[], int na, int b[], int nb){
    int r, i, contador = 0;
    if (tem_repetido1 (a, na) == 1) na = elimRepOrd1 (a, na);
    if (tem_repetido1 (b, nb) == 1 && a[0] != b[0]) nb = elimRepOrd1 (b, nb);
       for (r = 0; r < nb; r++){
       for (i = 0; i < na; i++){     
            if (b[r] == a[i]) contador++; 
           }
       }
       return contador;
   }

// ----------------------------------------------------------------------------

int ncomun (int i1,int n,int b[],int nb) {
    int i,r=0;
    for (i=0;i<nb;i++) {
        if (i1==i && b[i]==n) r=1;
    }
    return r;
}


int comunsOrd (int a[], int na, int b[], int nb){
    int i,r=0;
    for (i=0;i<na;i++) {
       r = r + ncomun(i,a[i],b,nb);
    }
    return r;
}