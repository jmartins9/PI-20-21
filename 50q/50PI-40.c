#include <stdio.h>

/*
  Defina uma função "void transposta (int N, float m[N][N])" que transforma
  uma matriz na sua transposta.
*/

void transposta (int N, float m [N][N]) {
    int il,ic,i=0;
    float t;
    for(il=0;il<N;il++) {     
        for (ic=i;ic<N;ic++) {
            t=m [il][ic];
            m [il][ic]= m [ic][il];
            m [ic][il]= t;
        }
        i+=1;
    }
    return;
}
