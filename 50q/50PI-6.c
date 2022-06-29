#include <stdio.h>

int qDig (unsigned int n) {
    int i;
    i=0;
    while (n>0) {
       n=n/10;
       i++;
    }
    printf ("%d",i);
    return i;
}

int main () {
    int n;
    scanf ("%d",&n);
    qDig (n);
}