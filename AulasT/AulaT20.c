/*


-----------------Memória Automática

int x;

Tempo de vida do x: tempo de vida do bloco onde é declarado




----------------Memória não automática/dinâmica (Heap)

int *x;
x=(int *) malloc (sizeof (int));
*x=3;

tempo de vida de *x: até que se faça free, ou até que o programa terminar




-----------------Memória pressistente 

Ficheiros

Ficheiros em c


tipo :
FILE * fp;

operações:
                 restrict- nao altera a string
 
FILE * fopen    (      string-com-nome       , modo-de-acesso )


modo de acesso: 

"r" (read) acesso exclusivo para leitura
    Se o ficheiro não existir---> ERRO (NULL)
 
"w" (write) acesso exclusivo para escrita 
    Se o ficheiro existir---> Apaga o que lá está

"a" (append) acesso exclusivo para escrita no fim do ficheiro 
  

int fclose (FILE *stream); (retorna 0 se correr bem)





int main () {
    FILE *fp;

    fp = fopen ("xpto","w");
   // if  (fp==NULL) printf("Não existe"\n);
   //else printf("ok"\n);
  
    fclose(fp);

    return 0;
}



fgetc -- retorna um caratere, caso contrario retorna EOF 

int main () {
    FILE *fp;

    fp = fopen ("xpto","r");
    if  (fp==NULL) printf("Não existe\n");
    else { // contar quantos caratere tem
        int conta;
        while (fgetc(fp)!=EOF)
              conta++;
        printf("tem %d carateres\n",conta);
    }
  
    fclose(fp);

    return 0;
}
    
wc FILE - linhas, palavras , carateres







int fputc (int c, FILE *stream);


int fprintf  (FILE, * char)

int fscanf  (FILE, *char)


posicionamento:

int fseek(FILE *stream, long offset, int whence); // coloca a cabeça numa determinada posição
            ficheiro     posição    referencial
                                       SEEK_SET  (a partir do inicio)
                                       SEEK_END  (a partir do ultimo)
                                       SEEK_CUR  (a partir da posiçao atual)


long ftell(FILE *stream);  // retorna a cabeça



int main () {
    FILE *fp;

    fp = fopen ("xpto","r");
    if  (fp==NULL) printf("Não existe\n");
    else { 
        fseek (fp,0,SEEK_END);
        conta= (int) ftell (fp);
        printf("tem %d carateres \n",conta);

    }
  
    fclose(fp);

    return 0;
}
    

Leitura/escrita 

modo de acesso :

"r+" acesso para leitura e escrita
     Se o ficheiro não existir---> ERRO (NULL)

"w+" acesso para leitura e esctrita
      Se o ficheiro existir---> Apaga o que lá está

"a+" acesso para leitura e escrita (esta ultima no fim do ficheiro)
      




leitura/escrita binária 

fread 
size_t fread(     void *ptr       ,   size_t size  ,    size_t nmemb  , FILE *stream);
             endereço de memória      numero de bytes = nmemb*size     ficheiro
                                        a transferir 

fwrite  igual ao fread , mas aqui vamos escrever naquele endereço do ficheiro aqueles numeros de bytes
















































*/