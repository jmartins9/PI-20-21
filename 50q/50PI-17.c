#include <stdio.h>

int maiorPrefixo (char s1[], char s2[]) {
    int i,comp;
    comp=0;
    for (i=0; s1[i]!='\0' && s2[i]!='\0';i++) {
         if (s1[i]==s2[i]) comp++;
         else {
         printf("%d",comp); 
         return comp;
         }
    }
    printf("%d",comp);
    return comp;
}

int main () {
    char s1[10]="Ola";
    char s2[10]="Ola mundo";
    maiorPrefixo(s1,s2);
}