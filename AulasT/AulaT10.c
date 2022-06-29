// Aula T10 (25.Mar)

void mergeSort (int v[],int N) {
    int m,i;
    int aux[N];
    if (N>1) {
        m=N/2;
        mergeSort(v,m);
        mergeSort(v+m,N-m);
        merge(v,m,v+m,N-m,aux);
        for (i=0;i<N;i++) v[i]=aux[i];
    }
}

void swap (int v[], int i, int j){
    int tmp;
    tmp=v[i];
    v[i]=v[j];
    v[j]=tmp;
}

//QUICK-SORT

/* escolher um elemento - x - do array (pivot)
  reorganizar o array deforma a que :
    --começa por aparecer todos os elementos menores ou iguais a x 
    --de seguida aparecem os restantes elementos (maiores que x)
*/

int partition (int v[],int N){
    /*usa como pivot v[N-1] 
       no inicio - _ _ _ _ _ ... _ _ X 
                  <= > > ? ? ... ? ? X
                     ^   ^
                     |   |
                     r   i    

                <= <= <= ... <= > > > > > X 
       swap(v,r,N-1)
       no final <= <= <= ... <= X > > > > > 
                                ^
                                |
                                r
    */
    int i,r;
    i=r=0;
    for (i=r=0;i<N-1;i++) {
        if (v[i]>v[N-1]);
        else {
            swap(v,r,i);
            r++;
        }
    }
        swap (v,r,N-1);
        return r;
}
    
void qSort (int v[],int N) {
    int p;
    if (N>1) {
        p= partition (v,N);
        qSort(v,p);
        qSort(v+p+1,N-p-1);
    }
}

/* Defenição de n-uplos em C

int x

int y[10]

y[2]=42



struct s{
    int sp; // primeira componente da struct
    int valores[10240]; // segunda componente da struct
}
    
struct s a; // a é do tipo struct s;

struct s a, b[40]; // b array de structs
a.sp=5 // A componente sp de a passa a 5
a.valores[3] = 42; 
b[2].sp=3; // vou à componente sp na struct da posição 2 do array de structs e substituo por 3
b[3].valores[5]=44;
*/
    
     
    







