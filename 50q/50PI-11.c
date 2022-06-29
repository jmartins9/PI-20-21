#include <stdio.h>
#include <string.h>

void strrev (char s[]) {
    int ts,is;
    char a;
    ts=strlen(s);
    for (is=0;is<ts/2;is++) {
         a=s[is];
         s[is]=s[ts-is-1];
         s[ts-is-1]=a;
    }
    return;
}