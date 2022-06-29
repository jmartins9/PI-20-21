#include <stdio.h>
#include <string.h>

int limpaEspacos (char texto[]) {
    int r=0;
    int ir,iw,n;
    n=strlen(texto);
    for (ir=0,iw=0;ir<n;ir++) {
        if (texto[ir]!=' ') {texto[iw]=texto[ir];iw++;r++;}
        else if (texto[ir]==texto[ir+1]);
             else {texto[iw]=texto[ir];iw++;r++;}
    }
    texto[iw]='\0';
    return r;
}