#include <stdio.h>

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;

typedef struct posicao {
   int x, y;
} Posicao;


int vizinhos (Posicao p, Posicao pos[], int N) {
    int i,r=0;
    for (i=0;i<N;i++) {
        if (pos[i].x==p.x && (pos[i].y==p.y+1 || pos[i].y==p.y-1)) r++;
        if (pos[i].y==p.y && (pos[i].x==p.x+1 || pos[i].x==p.x-1)) r++; 
    }
    return r;
}