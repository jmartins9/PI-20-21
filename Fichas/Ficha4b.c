#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void dumpV (int v[], int N){
    int i;
    putchar ('{');
    for (i=0; i<N; i++) printf ("%2d ", v[i]);
    putchar ('}');
}
void simNao (int x){
    if (!x) printf (" não ");
}

int ordenado (int a[], int N){
    int i, flag=1;
    for(i=0;i<N-1 && flag;i++) {
        if(a[i]>a[i+1]) flag=0;
    }
    return flag;
}

void merge (int a[], int na, int b[], int nb, int r[]){

    int i,ia,ib;
    for (i=0,ia=0,ib=0;ia<na && ib<nb;i++) {
        if(a[ia]<b[ib]) r[i]=a[ia++];
        else r[i]=b[ib++]; 
    }

    for(;ia<na;i++,ia++) {
        r[i]=a[ia];
    }

    for(;ib<nb;i++,ib++) {
        r[i]=b[ib];
    }
    
}

void swap (int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int menores(int v[],int N, int x) {
    int i,count=0;
    for(i=0;i<N;i++) 
        if (v[i]<=x) count++;

    return count;
}

int partition1 (int v[], int N, int x){
    int r = menores(v,N,x);
    int arrayaux[N];

    int i,ii,im;
    for (i=0,ii=0,im=r;i<N;i++) {
        if (v[i]<=x) arrayaux[ii++] = v[i];
        else arrayaux[im++] = v[i];
    }

    for(i=0;i<N;i++) {
        v[i]=arrayaux[i];
    }

    return r;
}


int partition (int v[], int N, int x){
    int count=menores(v,N,x);
    int ii,im;

    for (ii=0,im=count;ii<count && im<N;) {
        if (v[ii]<=x) ii++;
        else if (v[im]>x) im++;
        else swap(v,ii++,im++);
    }

    return count;
}




int main() {  
    int a [15] = {10, 3,45,56, 8,23,13,42,77,31,18,88,24,45, 1},
        b [10] = { 4,12,34,45,48,52,61,73,84,87}, 
        c [10] = { 1, 3, 8,22,33,35,38,41,44,49}, 
        d [50];
    int x;
    
    printf ("Testes\n\n");

    printf ("O array "); dumpV(a,15);
    simNao (ordenado (a,15)); printf (" está ordenado\n");
    printf ("O array "); dumpV(b,10);
    simNao (ordenado (b,10)); printf (" está ordenado\n");
    
    printf ("\n\nMerge dos arrays "); dumpV (b,10);
    printf ("\ne                "); dumpV (c,10); 
    merge (b, 10, c, 10, d);
    printf ("\nresulta em       "); dumpV (d,20);

    printf ("\n\n\nA partição do array  "); dumpV (a,15);
    printf ("\nusando 30 resulta em "); 
    x = partition (a,15,30); 
    dumpV (a,15); printf (" e retorna %d \n", x);

    printf ("\nFim dos testes\n");
    return 0;
}