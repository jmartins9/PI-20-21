#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 /* a função 
   int unionSet (int N, int v1[N], int v2[N], int r[N])
   que coloca no array \texttt{r} o resultado da união 
   dos conjuntos v1 e v2.
*/
int unionSet (int N, int v1[N], int v2[N], int r[N]){
    int c=0;
    int i;
    for(i=0;i<N;i++) {
        r[i]=v1[i] || v2[i];
    }
    return c;
}
