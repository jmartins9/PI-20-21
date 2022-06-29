#include <stdio.h>

int retiraNeg (int v[], int N){
    int r=0,ir,iw;
    for (ir=iw=0;ir<N;ir++) {
        if (v[ir]<0);
        else {v[iw]=v[ir];iw++;r++;}
    } 
    return r;
}

int main () {
    int s[10]={1,-3,5,9,-45,-78,9};
    retiraNeg(s,10);
}