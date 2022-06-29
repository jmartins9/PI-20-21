#include <stdio.h>
#include <string.h>

int maiorSufixo (char s1 [], char s2 []) {
    int conta,is1,is2;
    conta=0;
    is1=strlen(s1)-1;
    is2=strlen(s2)-1;
    for (;  is1>=0 && is2>=0;is1--,is2--) {
         if (s1[is1]==s2[is2]) conta++;
         else return conta;
    }
    return conta;
}

