#include <stdio.h>
#include <string.h>


char *mystrstr (char s1[], char s2[]) {
     int is1,is2=0,rt=0;
     if (s1[0]=='\0' && s2[0]=='\0') return s1;
     for (is1=0; s1[is1]!='\0';is1++) {
         if (s1[is1]==s2[is2] && is2==0) {
             rt=is1;
             is2++;
         }
         else if (s1[is1]==s2[is2]) is2++;
              else is2=0;
         if (s2[is2]=='\0') return s1+rt;
     }
  return NULL;
}

int main () {
  char s1[10]="ola manos";
  char s2[10]="anos";
  mystrstr(s1,s2);
}