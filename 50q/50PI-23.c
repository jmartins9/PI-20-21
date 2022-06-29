#include <stdio.h>
#include <string.h>


int palindroma (char s[]) {        
    int ini;
    int end,n;
    n=strlen(s);
    for (ini=0,end=strlen(s)-1;ini<n/2;ini++,end--) {
        if (s[ini]==s[end]);
        else return 0;
        }
    return 1;
}

// ababa     n=5 n/2=2
// 01234

// anaana   n=6 n/2=3
// 012345

int main () {
    char s[10]="ababa";
    palindroma(s);
}