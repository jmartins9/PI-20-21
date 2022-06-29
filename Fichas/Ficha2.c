#include <stdio.h>

float multInt1 (int n, float m) {
    float r = 0;
    int i;
    for (i=0;i<n;i++) {
        r+=m;
    }
    return r;
}

float multInt2 (int n, float m) {
    float r = 0;

    while (n>=1) {
        if (n%2!=0) r+=m;
        m*=2;
        n = n/2;
    }

    return r;
}




float multInt3 (int n, float m, int *count) {
    float r = 0;
    int c = 0;

    while (n>=1) {
        if (n%2!=0) {
            r+=m;
            c++;
        }
        m*=2;
        n = n/2;
    }

    (*count) = c;

    return r;
}

int mdc1 (int a, int b) {
    
    int menor = (a<b) ? a : b;
    int div = 0;

    while (!div) {
        if (a%menor==0 && b%menor==0) 
            div=menor;
        menor--;
    } 
}


int mdc2 (int a, int b) {

    while (a!=0 && b!=0) {
        if (a>b) a-=b;
        else if (a<b) b-=a;
        else a=0;
    }

    return (a!=0) ? a : b;
}


int mdc3 (int a, int b, int *count) {
    int c = 0;
    while (a!=0 && b!=0) {
        if (a>b) a = a%b;
        else if (a<b) b = b%a;
        else a=0;
        c++;
    }
    (*count)=c;
    return (a!=0) ? a : b;
}


int mdc4 (int a, int b, int *count) {
    int c = 0;
    while (a!=0 && b!=0) {
        if (a>b) a-=b;
        else if (a<b) b-=a;
        else a=0;
        c++;
    }
    (*count)=c;
    return (a!=0) ? a : b;
}

int fib (int n) {
    int r;
    if (n<2) r=1;
    else {
        int ant = 1;
        int ult = 1;
        int i;
        for (i=2,r;i<=n;i++) {
           r = ant + ult;
           ant = ult;
           ult = r;
        }
        
    }
    return r;
}


int fastfib (int n) {
    int r;
    if (n<2) r=1;
    else r = fastfib(n-1) + fastfib (n-2);
    return r;
}

int main()
{  int a,b,r1,r2,r3,r4, 
       c1=0, c2=0;
   float f, f1, f2, f3;
    
   printf ("Introduza dois números para input das funções de multiplicação: ");
   scanf ("%d", &a); scanf ("%f", &f);
   f1 = multInt1 (a,f);
   f2 = multInt2 (a,f);
   f3 = multInt3 (a,f, &c1);
   printf ("Resultados das multiplicações: %f, %f, %f (%d)\n", f1, f2, f3, c1);
   
   printf ("Introduza dois números para input das funções de multiplicaç~ão: ");
   scanf ("%d", &a); scanf ("%d", &b);

   r1 = mdc1 (a,b);
   r2 = mdc2 (a,b);
   r3 = mdc3 (a,b, &c1);
   r4 = mdc4 (a,b, &c2);
   printf ("Resultados do mdc: %d, %d, %d (%d), %d (%d)\n", r1, r2, r3, c1, r4, c2);
   
   printf ("Introduza um número para calcular o fib: ");
   scanf ("%d", &a);
   printf ("FastFib (%d) = %d \n", a, fastfib (a));
   printf ("Fib (%d) = %d \n", a, fib (a));
   
   return 0;
}