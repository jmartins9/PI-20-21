#include <stdio.h>

/*
  Defina uma função "int triSup (int N, int m [N][N])" que testa se uma
  matriz quadrada é triangular superior, i.e., que todos os elementos abaixo
  da diagonal são zeros.
*/

int triSup (int N, int m [N][N]) {
    int il,ic,r=1;
    for (il=0;il<N;il++) {
        for (ic=0;ic<N;ic++) {
            if (il>ic && m [il][ic]!=0) r=0;
        }
    }
    return r;
}
