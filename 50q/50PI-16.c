#include <stdio.h>

int difConsecutivos(char s[]) {
    int is,maxdif1=0,maxdif2=1;
       for (is=0;s[is]!='\0';is++) {

            if (s[is+1]==' ');
            else if (s[is+1]=='!') maxdif1=maxdif2;
            else if (s[is]!=s[is+1]) {
                maxdif2++;
            }
            else if (maxdif1<=maxdif2) {
                maxdif1=maxdif2;
                maxdif2=1;
            }
       }
    return maxdif1;
}