#include <stdio.h>
/* a função 
   int cardinalMSet (int N, int v[N]) que calcula o 
   número de elementos do multi-conjunto v.
*/

int cardinalMSet (int N, int v[N]){
    int c = 0,i;
    for (i=0;i<N;i++) {
        c+=v[i];
    }
   	return c;
}