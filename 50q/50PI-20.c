#include <stdio.h>

int contaPal (char s[]) {
    int indice;
    int npalavras;
    npalavras=indice=0;
    if (s[indice]=='\0') return 0;
    while (s[indice]==' ' || s[indice]=='\n') indice++;
    while (s[indice]!='\0') {
         if (s[indice]!=' ') indice++;
         else {
             npalavras++;
             while (s[indice]==' ') indice++;}
    }
    if (s[indice-1]!=' ' && s[indice-1]!='\n' && s[indice]=='\0') npalavras++;
    return npalavras;
}

