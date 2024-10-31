#include <stdio.h>
#include <omp.h>
#include <semaphore.h>

#define size 20000
int i,j;
int A[size],B[size],C[size];

sem_t sem_A_B, sem_B_C;

void calc_A() {
    A[0]=15;
    for (i=1;i<size;i++) {
        for(j=0;j<size;j++)
            A[i]=(A[i-1]+i*3+15+j)%1000;
    }
}

void calc_B() {
    B[0] = 1; 
    for(i = 1; i < size; i++){
        for(j=0;j<size;j++)
            B[i] = (B[i-1]*3 + A[i-1]+j)%1000;
    }
}

void calc_C() {
    C[0] = 1; 
	for(i = 1; i < size; i++){
            for(j=0;j<size;j++)
		        C[i] = (C[i-1] + B[i-1] * 2+j)%1000;
    }
}

int main() {
    printf("INICIO\n");
    fflush(stdout);

    sem_init(&sem_A_B,0,0);
    sem_init(&sem_B_C,0,0);

    #pragma omp parallel num_threads(3)
    {
        if (omp_get_thread_num() == 0) {
            calc_A();
            sem_post(&sem_A_B);
        } else if (omp_get_thread_num() == 1) {
            sem_wait(&sem_A_B);
            calc_B();
            sem_post(&sem_B_C);
        } else {
            sem_wait(&sem_B_C);
            calc_C();
        }
    }

    sem_destroy(&sem_A_B);
    sem_destroy(&sem_B_C);

    printf("C[0]=%d  C[1]=%d  C[%d]=%d\n",C[0],C[1],(size-1),C[size-1]);  
	fflush(stdout);
	printf("FIM\n");
    fflush(stdout);
}