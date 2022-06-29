#include <stdio.h> 

int contaVogais (char s[]) {
    int conta=0;
    int i;
    for (i=0;s[i]!='\0';i++) {
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||
            s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'   ) conta++;
    }
    return conta;
}