#include <stdio.h>

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;

typedef struct posicao {
   int x, y;
} Posicao;


Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i;
    for (i=0;i<N;i++) {
        if(mov[i]==Norte) inicial.y+=1;
        if(mov[i]==Sul) inicial.y-=1;
        if(mov[i]==Este) inicial.x+=1;
        if(mov[i]==Oeste) inicial.x-=1;
    }
    return inicial;
}