#include <stdio.h>

void strnoV (char t[]){
     int i,icopy=0,i1;
     for(i=0;t[i]!='\0';i++) {
        if(t[i]!='a' && t[i]!='e' && t[i]!='i' && t[i]!='o' &&
           t[i]!='u' && t[i]!='A' && t[i]!='E' && t[i]!='I' &&
           t[i]!='O' && t[i]!='U') {
               t[icopy]=t[i];
               icopy++;
               } 
     }
     t[icopy]='\0';
}

int main () {
    char t[20]="aaaaaaaaaaa";
    strnoV(t);
}