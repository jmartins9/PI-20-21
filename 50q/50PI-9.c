#include <stdio.h>
#include <string.h> 

int mystrcmp(char s1[], char s2[]) {
    int i=0,r=50000,ts1=0,ts2=0;
    ts1=strlen(s1);
    ts2=strlen(s2);
    for (i=0;s1[i]!='\0' && s2[i]!='\0' && r!=-1 && r!=1;i++) { 
        if (s1[i]<s2[i]) r=-1;
        if (s1[i]>s2[i]) r=1; 
    }
    if (ts1==ts2 && r==50000) r=0;
    if (ts1<ts2 && r==50000) r=-1;
    if (ts1>ts2 && r==50000) r=1;
    return r;
}

int main () {
    char s1[10]="olaamigos";
    char s2[10]="olaamigos";
    mystrcmp(s1,s2);
}