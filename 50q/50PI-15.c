#include <stdio.h> 

int iguaisConsecutivos (char s[]) {
    int is,maxcons1=0,maxcons2=1;
       for (is=0;s[is]!='\0';is++) {
            if (s[is]==s[is+1]) {
                maxcons2++;
            }
            else if (maxcons1<maxcons2) {
                maxcons1=maxcons2;
                maxcons2=1;

            }
       }
    return maxcons1;
}