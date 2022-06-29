#include <stdio.h> 
#include <string.h>

int contida (char a[], char b[]) {
    int ia,ib;
    int r;
    for (ia=ib=0;a[ia]!='\0' && b[ib]!='\0';)  {
         while (b[ib]!='\0') {
             if (b[ib]==a[ia]) ia++,ib=0;
             else ib++;
         }
    }
    if (ia!=strlen(a) && ib==strlen(b)) r=0;
    else  r=1;
    return r;
}

int main () {
    char a[20]="braga";
    char b[20]="bracarense";
    contida(a,b);
 }
