/*

/////////////////////////////////////////ARVORES BINARIAS////////////////////////////////////////////////

typedef struct arvore {
    int valor;
    struct arvore *esq,*dir;
} *Arv;


int compArv (Arv a) {
    int r=0;
    if (a!=NULL) r = 1 + compArv(a->esq) + compArv(a->dir);
    return r;
}

Arv arvFromArray (int v[],int N) {
    Arv r = NULL;
    int m = N/2;
    if (N>0) {
        r=malloc(sizeof (struct arvore));
        r->valor = v[0];
        r->esq = arvFromArray (v+1,m);
        r->dir = arvFromArray (v+1,N-m-1);
    }
    return r;
}




*/