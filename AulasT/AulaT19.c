/*


int search (Arv a, int x) {
    while(a!=NULL && a->valor!=x) {
         if (a->valor>x) a=a->esq;
         else a=a->dir;
    }
    return (a!=NULL);
}


Arv insere (Arv a, int x) {
    
    if (a==NULL) {
        a=malloc (sizeof(struct arvore));
        a->valor=x;
        a->esq=a->dir=NULL;
    }
    else if (x < a->valor)  a->esq=insere(a->esq,x);
         else  a->dir=insere(a->dir,x);
    
    return a;
}

// ou 

Arv insere (Arv a, int x) {
    Arv pt=a,ant;
    while (pt!=NULL) {
        ant = pt;         
        if (x< pt->valor) pt=pt->esq;
        else pt = pt->dir;
    }
    pt = malloc (sizeof (struct arvore));
    pt->valor=x;
    pt->esq=pt->dir=NULL;

    if (a!=NULL) {
       if (x < ant->valor) ant->esq=pt;
       else ant->dir=pt;
    }
    else a=pt;
    return a;
}

// ou 

Arv insere (Arv a, int x) {
    
    Arv *sitio;
    sitio=&a;
    
    while (*sitio!=NULL) 
        if (x< (*sitio)->valor) sitio=&((*sitio)->esq);
        else sitio = &((*sitio)->dir);

    (*sitio)= malloc (sizeof (struct arvore));
    (*sitio)->valor=x;
    (*sitio)->esq=(*sitio)->dir=NULL;

    return a;
}





*/