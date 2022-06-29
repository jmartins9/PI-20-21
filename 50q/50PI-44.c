#include <stdio.h>

/* a função 
   int intersectMSet (int N, int v1[N], int v2[N], int r[N])
   que coloca no array r o resultado da intersecção 
   dos multi-conjuntos v1 e v2.
*/

int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
    int c = 0,i;
    for (i=0;i<N;i++) {
        if (v1[i] <= v2[i]) {
            r[i]=v1[i];
        }
        else r[i]=v2[i];
    }
    return c;
}
