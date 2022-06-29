#include <stdio.h>

int procura1 (char x,char v[], int cont){
    int i,j;
    i=0;
    cont = 0;
    for (i=0; v[i] != '\0' ; i++){
        if (x == v[i]) {
            cont++;
        }
    }
    return cont;
}

char charMaisfreq (char s[]){
    int i,cont;
    char m;
    cont = 0;
    m = s[0];
    procura1(m,s,cont);
    for (i=1; s[i] != '\0'; i++){
        if (cont < procura1(s[i],s,cont)){
            cont = procura1(s[i],s,cont);
            m = s[i];
        }
    }
    return m;
}