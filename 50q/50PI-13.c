#include <stdio.h>

void truncW (char t[], int n) { 
     int i,icopia=0,trunc=n;
     for (i=0;t[i]!='\0';i++) {
         if ( t[i]!=' ' && trunc>0) {
            t[icopia]=t[i];
            icopia++;
            trunc--;
         }
         if (t[i]==' ') {
            t[icopia]=' ';
            icopia++;
            trunc=n;
         }
     }
     t[icopia]='\0';
}


int main () {
    char s1[30]="  aaaaaaaaaaaaaaaaaa  ";
    truncW(s1,2);
}