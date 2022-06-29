#include <stdio.h>

char *mystrcpy(char dest[], const char source[]) {
    int i;
    for (i=0;source[i]!='\0';i++) {
        dest[i]=source[i];
    }
    dest[i]='\0';
    return dest;
}

int main () {
    char s1[5]={"ola "};
    char s2[6]={"mundo"};
    mystrcpy (s1,s2);
    return 0;
}