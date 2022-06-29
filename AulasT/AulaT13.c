/* 

malloc(para reservar memória)
      (realloc,calloc)

free (para libertar memória)

------------------------------------------------------

listas em C: 

1º Listas de inteiros: 
inspirar no tipo do haskell 

[int] = [] | Int : [Int]

Requesitos : como representar a lista vazia?
             como representar listas não vazias 

struct lista {
    int valor;   // cabeça
    struct lista cauda;
} // errado , o tamanho é infinito 

existe um endereço especial para identificar listas vazias:
NULL-definido em stdio

typedef struct lista {
    int valor;
    struct lista *cauda;
} *Lista;



int main () {
    Lista x;

    // x = []
    x=NULL;

    // y = [42]
    y = malloc (sizeof(struct lista)); // inicia o enderço de memoria y , pois no y só tinha lixo e atribuiu um endereço de memória valida
    y->valor = 42;
    y->cauda = NULL; 
   

    // z = [1,2,3]
    z = malloc (sizeof (stuct lista));
    z->valor = 1;
    z->cauda = malloc (sizeof (struct lista));
    z->cauda->valor = 2;
    z->cauda->cauda = malloc (sizeof (struct lista));
    z->cauda->cauda->valor = 3;
    z->cauda->cauda->cauda = NULL;


    // em vez de cauda usa se prox (proximo elemento) fazm mais sentido 

}

Lista newLista (int x,Lista l) {  // igual a x : l
    Lista r;
    r=malloc (sizeof (struct lista));
    r->valor = x;
    r->prox = l;
    return r;
} 


no main agora : 

z = newlista (3,z);
z = newlista (2,z);
z = newlista (1,z);

















*/