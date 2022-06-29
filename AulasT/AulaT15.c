/*




Lista cloneL (Lista l) {
  Lista r,ult,*sitio;

  sitio=&r;

  while (l!=NULL) {
      *sitio = malloc(sizeof(struct lista));
      (*sitio)->valor=l->valor;
      l=l->prox;
      sitio=&((*sitio)->prox);

  }
  *sitio=NULL;

  return r;
}













*/