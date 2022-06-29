#include <stdio.h>

/*
  Defina uma função "void addTo (int N, int M, int a [N][M], int b[N][M])"
  que adiciona a segunda matriz à primeira.
*/

void addTo(int N, int M, int a [N][M], int b[N][M]) {
    int il,ic;
    for (il=0;il<N;il++) {
        for (ic=0;ic<M;ic++) {
            a [il][ic] = a [il][ic] + b [il][ic];
        }
    }
    return;
}