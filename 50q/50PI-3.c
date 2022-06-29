#include <stdio.h>

int main () {
    int n,primeiro,segundo; 
    primeiro = scanf ("%d",&n);
    while (n!=0) {
        scanf ("%d",&n);
        if (n > primeiro) {
            segundo = primeiro; 
            primeiro = n;
        }
        else if (n > segundo) (segundo = n);
    } 
    printf ("%d",segundo);
}


