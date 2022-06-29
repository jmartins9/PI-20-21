#include <stdio.h>
#include <string.h>

int sufPref (char s1[], char s2[]){
    int i,cont;
    cont=0;
    int cmp1 = strlen (s1) - 1 ;
    int cmp2 = strlen (s2) - 1 ;
    
    for (i = cmp2 ; i>=0 && (cmp1>=0) ; i--){
        if ((s1[cmp1] == s2[cmp2])){
            cont++;
            cmp1--;
            cmp2--;
        }
        else {
             cmp2 --;
             cont = 0;
             cmp1 = strlen(s1) - 1;
             }
    }
    return cont;
}

int main () {
    char s1[20]="ola mundo";
    char s2[20]="mundo cruel";
    sufPref(s1,s2);
}