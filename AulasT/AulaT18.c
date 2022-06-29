/*



int travessiaParaArray (Arv a, int v[], int N) {
     int r=0;
     int t=(N-1)/2
     if (a==NULL && N<=0);      
     else {                                            //pre order
         v[r]=a->valor;
         r++;
         r+=travessiaParaArray (a->esq,v+r,N-r);
         r+=travessiaParaArray (a->dir,v+r,N-r); 
     }
     return r;
}

int travessiaParaArray (Arv a, int v[], int N) {
     int r=0;
     int t=(N-1)/2
     if (a==NULL N<=0);     
     else {                                             //in order
         r+=travessiaParaArray (a->esq,v+r,N-r);
         if (r<N) {
         v[r]=a->valor;
         r++;
         r+=travessiaParaArray (a->dir,v+r,N-r); 
         }
     }
     return r;
}



// Árvores de procura (BST - Binary Search Tree)
 
int search (Arv a,int x) {
    // retorn verdadeiro se x existe em a;
    int r;
    
    if (a==NULL) r=0;
    else if (a->valor == x) r=1;
    else if (a->valor > x) r=search(a->esq,x);
    else r=search (a->dir,x);
    
    return r;
}


*/