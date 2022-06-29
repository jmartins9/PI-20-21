#include <stdio.h>

int main () {
    int n;
    float m,i;
    
    scanf ("%d",&n);
    m=n;
    i=1;
    while (n!=0) {
        scanf ("%d",&n);
        m = m + n;
        i++;
    }
    printf("%f\n",m/i);
}
