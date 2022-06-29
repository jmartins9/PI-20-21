#include <stdio.h>

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;

typedef struct posicao {
   int x, y;
} Posicao;



int maiscentral (Posicao pos[], int N) {
    int i,mindistancia=0,distancia=0,r=0;
    mindistancia=((pos[0].x)*(pos[0].x)+(pos[0].y)*(pos[0].y)); 
    for (i=1;i<N;i++) {
         distancia=((pos[i].x)*(pos[i].x)+(pos[i].y)*(pos[i].y));
         if (mindistancia>distancia) {
             mindistancia=distancia;
             r=i;
         }
    }
    return r;
}


