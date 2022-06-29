#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

void dumpV (int v[], int N){
    int i;
    for (i=0; i<N; i++) printf ("%d ", v[i]);
}
void imprimeAluno (Aluno *a){
    int i;
    printf ("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for(i=1; i<6; i++) printf (", %d", a->miniT[i]);
    printf (") %5.2f %d\n", a->teste, nota(*a));
}

int nota (Aluno a){ // media dos mini testes (entre 0 e 2) + teste * 0.9 =   < 9.5 nao passa , maneira mais simples 

    int i;
    float sum=0;
    for(i=0;i<6;i++) {
        sum+=a.miniT[i];
    }
    sum=sum/6;
 
    sum+=(a.teste)*0.9;

    if (sum<9.5) sum=0;
    return round(sum);
}

void ordenaPorNum (Aluno t [], int N){
    int i,j;
    Aluno aux;
    for(i=0;i<N;i++) {
        for(j=0;j<N-1-i;j++) {
            if (t[j].numero>t[j+1].numero) {
                aux = t[j];
                t[j] = t[j+1];
                t[j+1] = aux;
            }            
        }
    }
}

int  procuraNum (int num, Aluno t[], int N){
    int ret = -1;

    int i;
    for(i=0;i<N && ret==-1;i++) 
        if (t[i].numero==num) ret=i;    
    
    return ret;
}

int procuraNumInd (int num, int ind[], Aluno t[], int N){
    int i,ret=-1;
    for(i=0;i<N && ret==-1;i++) {
        if(t[ind[i]].numero==num) ret=i;
    }
    return ret;
}

void criaIndPorNum (Aluno t [], int N, int ind[]){

    int i,j,aux;
    for(i=0;i<N;i++) {
        ind[i]=i;
    }

    for(i=0;i<N;i++) {
        for(j=0;j<N-1-i;j++) {
            if(t[ind[j]].numero>t[ind[j+1]].numero) {
                aux = ind[j];
                ind[j] = ind[j+1];
                ind[j+1] = aux;
            }   
        }
    }

    
}
void criaIndPorNome (Aluno t [], int N, int ind[]){
    
    int i,j,aux;
    for(i=0;i<N;i++) {
        ind[i]=i;
    }

    for(i=0;i<N;i++) {
        for(j=0;j<N-1-i;j++) {
            if(strcmp(t[ind[j]].nome,t[ind[j+1]].nome)>0) {
                aux = ind[j];
                ind[j] = ind[j+1];
                ind[j+1] = aux;
            }   
        }
    }

}

void imprimeTurmaInd (int ind[], Aluno t[], int N){
    int i;
    for (i=0;i<N;i++) {
         imprimeAluno (&(t [ind[i]]));
    }
}


int main() {
    Aluno Turma1 [7] = {{4444, "André", {2,1,0,2,2,2}, 10.5}
                       ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                       ,{8888, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{2222, "Joana", {2,0,2,1,0,2},  3.5}
                       ,{7777, "Maria", {2,2,2,2,2,1},  5.5}
                       ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
                       ,{5555, "Diogo", {2,2,1,1,1,0},  8.5}
                       } ;
    int indNome [7], indNum [7];
    int i;
    
    printf ("\n-------------- Testes --------------\n");
    
    //ordenaPorNum (Turma1, 7);

    //printf ("procura 5555: %d \n", procuraNum (5555, Turma1, 7));
    //printf ("procura 9999:%d \n", procuraNum (9999, Turma1, 7));

    //for (i=0; i<7; imprimeAluno (Turma1 + i++));
    
    //criaIndPorNum (Turma1, 7, indNum);
    
    criaIndPorNome (Turma1, 7, indNome);

    //imprimeTurmaInd (indNum, Turma1, 7);
    imprimeTurmaInd (indNome, Turma1, 7);

    //printf ("procura 5555:%d \n",  procuraNumInd (5555, indNum, Turma1, 7));
    //printf ("procura 9999:%d \n",  procuraNumInd (9999, indNum, Turma1, 7));

    printf ("\n---------- Fim dos Testes ----------\n");
    
    return 0;
}
