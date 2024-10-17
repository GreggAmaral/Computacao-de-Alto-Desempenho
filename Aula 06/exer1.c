#include <stdio.h>
#include <omp.h>
//#include "mede_time.h"

#define SIZE 1000
#define num_t 2

int a[SIZE][SIZE];
int b[SIZE][SIZE];
int c[SIZE][SIZE];
int d[SIZE][SIZE];
int ab[SIZE][SIZE];
int cd[SIZE][SIZE];
int r[SIZE][SIZE];

int main() {

    //TIMER_CLEAR;
    //TIMER_START;

    #pragma omp parallel for num_threads(2) private(i,j) //inicializar as matrizes
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            a[i][j] = (i*3+j*2)%SIZE;
            b[i][j] = (i*4+j*2)%SIZE;
            c[i][j] = (i*5+j*3)%SIZE;
            d[i][j] = (i*2+j*4)%SIZE;
            ab[i][j] = 0;
            cd[i][j] = 0;
            r[i][j] = 0;
        }
    }

    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section // Seccao de AXB
        {
            #pragma omp parallel for private(i,j,k)
            for(i = 0; i < SIZE; i++) {
                for (k = 0; k < SIZE; k++) 
                    for (j = 0; j < SIZE; j++)
                        ab[i][j] = ab[i][j] + a[i][k] * b[k][j];
            }
        }

        #pragma omp section // Seccao de CXD
        {
            #pragma omp parallel for private(i,j,k) 
            for(i = 0; i < SIZE; i++) {
                for (k = 0; k < SIZE; k++) 
                    for (j = 0; j < SIZE; j++)
                        cd[i][j] = cd[i][j] + c[i][k] * d[k][j];	            }
        }
    }

    #pragma omp parallel for num_threads(4) //executa a soma
    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++)
            r[i][j] = ab[i][j] + cd[i][j];


    //TIMER_STOP;
    //printf ("Tempo de execucao: %12.7f\n",TIMER_ELAPSED);

    printf("r[0][0] = %d\n",r[0][0]);
    fflush(stdout);

	printf("r[10][10] = %d\n",r[10][10]);
    fflush(stdout);

	printf("r[999][999] = %d\n",r[999][999]);
    fflush(stdout);

	return 0;
}