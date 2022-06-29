/*

newLista(1,newLista(2,newLista(3,NULL)));

Lista fromArray ( int v[],int N) {
    // constroi uma lista com os N elementos v 
    Lista r=NUll;
    int i;
    for (i=N-1;i>=0;i--) {
        r = newLista (v[i],r);
    }
    return r;
}

Lista fromArray ( int v[],int N) {
    // constroi uma lista com os N elementos v 
    Lista r=NUll;
    if (N>0) {
        r = newLista (v[0],fromArray (v+1,n-1));
    }
    return r;
}

Lista clonel (Lista l) {
      Lista r,cauda;
      if (l==NULL) r=NULL;
      else { cauda = cloneL (l->prox);
             r = newLista (l->valor,cauda);
          } 
      return r;
}


*/