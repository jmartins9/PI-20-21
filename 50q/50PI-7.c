#include <stdio.h>

char *mystrcat (char s1[], char s2[]) {
     int i,j;
     for (i=0;s1[i]!='\0';i++);
     for (j=0;s2[j]!='\0';j++) {
         s1[i]=s2[j];
         i++;
     }
     s1[i]='\0';
  return s1;
}

void imprime (char s[],int N) {
     int i;
     for (i=0;i<N;i++) {
         printf ("%c",s[i]);
     }
}

int main () {
    char s1[5]={"ola "};
    char s2[6]={"mundo"};
    imprime (mystrcat (s1,s2),11);
    return 0;
}