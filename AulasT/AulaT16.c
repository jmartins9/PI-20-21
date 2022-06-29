/*


Lista insereOrd (Lista l, int x) {
    // l está ordenada

    Lista nova, pt = l,ant;
    nova= malloc (sizeof (struct lista));
    nova->valor = x;

    if (l==NULL || l->valor >x) {
    
    //inserir no inicio 
    
    nova->prox=l;
    l=nova; 
    
    }
    else {

    // percorrer a lista até encontrar um elemento maior do que x 

    while (pt !=NULL && pt->prox < x) {
        ant=pt;
        pt=pt->prox;
    }
   

    // inserir a célula nesse sitio da lista

    nova->prox=pt;
    ant->prox=nova;
    }

    return l;
}



Lista insereOrd (Lista l, int x) {

    Lista nova, *sitio;
    nova= malloc (sizeof (struct lista));
    nova->valor = x;
    sitio=&l;

    while (*sitio!=NULL && (*sitio)->valor < x) {
        sitio = &( (*sitio)->prox );
    }

    nova->prox=*sitio;
    *sitio=nova;



    return l;
}


int insereOrd (Lista *l, int x) {

    //sucesso se possivel

    Lista nova;
    nova= malloc (sizeof (struct lista));
    nova->valor = x;

    while (*l!=NULL && (*l)->valor < x) {
        l = &( (*l)->prox );
    }

    nova->prox=*l;
    *l=nova;


    return 0;
}

Lista removeOrd (Lista l,int x) {
    //assumindo que l está ordenado 
    Lista pt=l,ant;

    //percorre a lista até encontrar

    while (pt!=NULL && pt->valor < x) {
        ant = pt; pt = pt->prox;
    }

    if (pt!=NULL && pt->valor == x) {
        // encontrado 
        if (pt!=l) ant->prox=pt->prox;
        else l=l->prox;
        free (pt);
    }
    else {
        // nao existe
    }
    return l;
}


Lista removeOrd (Lista l , int x) {
    Lista pt,*sitio;
    sitio=&l;
    while (*sitio!=NULL && (*sitio)->valor < x) {
     sitio = &((*sitio)->prox);
    }
    if (*sitio!=NULL && (*sitio)->valor==x) {
       pt = *sitio;
       (*sitio)=(*sitio)->prox;
       free(pt);
    }


}















*/