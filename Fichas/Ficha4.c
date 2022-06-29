#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evogal (char c) {
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
            c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
}

int contaVogais (char *s) {
    int count = 0;

    int i;
    for (i=0;s[i]!='\0';i++) {
        if (evogal(s[i])) count++;
    }
    return count;
}

int retiraVogaisRep (char *s){
    int count = 0;
    int tam = strlen(s); 
    if (tam>1) {
        int i, i2;

        for(i=1,i2=0;i<tam;i++) {
            if (s[i]!=s[i2] || (s[i]==s[i2] && !evogal(s[i]))) s[++i2]=s[i];     
            else count++;
        }
        s[++i2]='\0';

    }
    return count;
}

int duplicaVogais (char *s){

    int i,j,count=0,tam;
    for (i=0;s[i]!='\0';i++) {
        if (evogal(s[i])) {
            tam=strlen(s);
            s[tam+1]='\0';
            for(j=tam-1;j>i;j--) {
                s[j+1]=s[j];
            }
            s[i+1]=s[i];
            count++;
            i++;
        }
    }

    return count;
}

int main()
{   char s1 [100] = "Estaa e umaa string coom duuuplicadoos";
    int x;
    
    printf ("Testes\n");
    printf ("A string \"%s\" tem %d vogais\n", s1, contaVogais (s1));
    
    x = retiraVogaisRep (s1);
    printf ("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s1);
    
    x = duplicaVogais (s1);
    printf ("Foram acrescentadas %d vogais, resultando em \"%s\"\n", x, s1);
    
    printf ("\nFim dos testes\n");

    return 0;
}