#include <stdio.h>
#include <omp.h>

int count =0;
int x;
int a[1000][1000];

void init_matrix(){   
    int i,j;
    #pragma omp parallel num_threads(2) shared(a) private(i,j)
    {
        #pragma omp for
        for(i = 0; i < 1000; i++){  
            for (j = 0; j < 1000; j++){
                a[i][j]=(2*i-j)%1000 ;
            }
        }
    }
}

void busca(){
    int i,j;
    #pragma omp parallel num_threads(2) shared(a, x) private(i,j)reduction(+:count)
    {
        #pragma omp for
        for(i = 0; i < 1000; i++){ 
            for (j=0;j<1000;j++){
                if (a[i][j] == x){
                    count++; 
                }
            }
        }
    }
}

int main(){

    printf("Digite um numero de 0 a 9999:");
    fflush(stdout);
    scanf("%d",&x);
    init_matrix();
    busca();
    printf("NUMERO DE OCORRENCIAS= %d\n", count);
    fflush(stdout);
}