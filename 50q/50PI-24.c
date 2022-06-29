#include <stdio.h>
#include <string.h>
/* a função remRep deve remover da string argumento
   todos os caracteres que se repetem sucessivamente
   deixando lá apenas uma cópia
*/

int remRep (char texto []) {
    int r = 0;
    int i,w=0;
    int n=strlen(texto);
    for (i=0;i<n;i++) {
        if (texto[i]==texto[i+1]);
        else {
             texto[w]=texto[i];
             w++;
             r++;       
        }
    }
    texto[w]='\0';
    return r;
}
int main () {
    char TEXTO[30]="aaaaaaaaaaaaaaaaaaaaaa";
    remRep(TEXTO);
}