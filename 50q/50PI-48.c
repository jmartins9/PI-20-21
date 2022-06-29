#include <stdio.h>

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;

typedef struct posicao {
   int x, y;
} Posicao;

int alterax (int x,int x1,int i,Movimento mov[],int N) {
    int deltax;
    deltax = x1-x;
    if (deltax>0) {
       for (;deltax!=0 && i<N;deltax--) {
           mov[i++]=Este;
       }
    }
    if (deltax<0) {
       for (;deltax!=0 && i<N;deltax++) {
           mov[i++]=Oeste;
       }
    }
    return i;
}

int alteray (int y,int y1,int i,Movimento mov[],int N) {
    int deltay;
    deltay = y1-y;
    if (deltay>0) {
       for (;deltay!=0 && i<N;deltay--) {
           mov[i++]=Norte;
       }
    }
    if (deltay<0) {
       for (;deltay!=0 && i<N;deltay++) {
           mov[i++]=Sul;
       }
    }
    return i;
}


int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i=0,deltax=abs(final.x-inicial.x),deltay=abs(final.y-inicial.y);
    i= alterax(inicial.x,final.x,i,mov,N);
    i= alteray(inicial.y,final.y,i,mov,N);
    if (deltax+deltay>N) return -1;
    else return i;
}