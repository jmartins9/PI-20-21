#include <stdio.h>

int trailingZ (unsigned int n) {
    int i;
    i=0;
    if (n==0) (i=32);
    while (n>1) {
        if (n%2==0) (i=i+1);
        n=n/2;
    }
    printf("%d",i);
    return i;
}

int main () {
    int n;
    scanf ("%d",&n);
    trailingZ (n);
}