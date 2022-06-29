#include <stdio.h>

int main () {
    int n,max;
    max = scanf ("%d",&n);
    while (n!=0) {
        scanf ("%d",&n);
        if (max > n) max;
        else (max = n); 

    }
    printf("%d\n",max);
}
