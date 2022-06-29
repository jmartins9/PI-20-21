#include <stdio.h>


void ex1a() {
    int x [15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int *y, *z, i;
    y = x; // 1
    z = x+3;  // 4

    for (i=0; i<5; i++) {
        printf ("%d %d %d\n",x[i], *y, *z);  
        y = y+1; z = z+2;
    }

    /*
    1 1 4
    2 2 6 
    3 3 8 
    4 4 10 
    5 5 12
    */

}


void ex1b() {

    int i, j, *a, *b;
    i=3; j=5;
    a = b = 42;  
    a = &i; b = &j;  // *a = 3  *b = 5
    i++; // *a = 4 
    j = i + *b;  // j = 4 + 5 = 9 
    b = a; // *b = 4
    j = j + *b; // j = 9 + 4 = 13
    printf ("%d\n", j);

}

void swapM (int *x, int *y) {
    int aux = *x; // aux = 3
    *x = *y; // *x = 5
    *y = aux; // *y = 3
}

void swap (int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int soma (int v[], int N) {
    int sum=0,i;
    for (i=0;i<N;i++) 
        sum+=v[i];
    return sum;
}

void inverteArray (int v[], int N) {
    
    int i;
    for(i=0;i<N/2;i++) {
        swap(v,i,N-i-1);
    }

}

int maximum (int v[], int N, int *m) {
    int r;
    if (N>0) {
        r = 0;
        int i = 0;
        (*m) = v[i++];
        for (;i<N;i++) {
            if (v[i]>(*m)) (*m)=v[i];
        }    
    }
    else r = -1;
    return r;
}


void quadrados (int q[], int N) {
    // (a + 1)2 = a2 + (2 ∗ a + 1)
    int i=0,a=0;
    q[i++]=0;
    for (;i<N;i++,a++) {
        q[i]= q[i-1] + a*2 + 1;
    }

}


void pascal (int v[], int N) {
    int i,j;
    v[0]=1;
    
    for(i=1;i<=N;i++) {
        v[i]=1;
        for(j=i-1;j>0;j--) {
            v[j]=v[j]+v[j-1];
        }        
    }
}

void desenhaPascal (int v[], int N) {
    int i,j;
    v[0]=1;
    
    for(i=1;i<=N;i++) {
        v[i]=1; 
        printf("%d ",v[i]);
        for(j=i-1;j>0;j--) {
            v[j]=v[j]+v[j-1];
            printf("%d ",v[j]);
        }
        if (i>1) printf("1 \n");
        else printf("\n");        
    }
}



int main (int argc, char *argv[]) {
    
    printf("Ex1:\n");
    ex1a();
    ex1b();

    printf("\nEx2:\n");
    int x = 3, y = 5;
    swapM (&x, &y);
    printf ("%d %d\n", x, y);

    printf("\nEx3:\n");
    int a [15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    swap(a,0,14);
    printf("%d %d\n",a[0],a[14]);

    printf("\nEx4:\n");
    printf("%d\n",soma(a,15));

    printf("\nEx5:\n");
    int i;
    swap(a,0,14);
    inverteArray(a,15);
    for (i=0;i<15;i++) {
        printf("%d ",a[i]);
    }
    
    printf("\n\nEx6:\n");
    int max;
    maximum(a,15,&max);
    printf("%d\n",max);    

    printf("\nEx7:\n");
    quadrados(a,15);
    for (i=0;i<15;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");

    printf("\nEx8:\n");
    desenhaPascal(a,5);


    return 0;
}