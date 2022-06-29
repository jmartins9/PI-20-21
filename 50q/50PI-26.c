#include <stdio.h>

/* a função
   void insere (int v[], int N, int x) 
   que insere um elemento (x) num vector ordenado.
   Assuma que as N primeiras posições do 
   vector estão ordenadas e que por isso, após a 
   inserção o vector terá as primeiras N+1 posições 
   ordenadas.
*/

void insere (int s[], int N, int x){
    int ir,iw;
    for (ir=N-1,iw=N;ir>=0;ir--,iw--) {
        if (x>=s[ir]) {s[iw]=x;return;}
        else s[iw]=s[ir];
    }
    s[iw]=x;
    return;
}