#include <stdio.h>

int bitsUm (unsigned int n) {
    int i;
    for (i=1;n>1;) {
        if (n%2==1) (i=i+1);
        n=n/2;
    }
    printf ("%d\n",i);
    return i;
}

int main () {
    int n;
    scanf("%d",&n);
    bitsUm (n);
}