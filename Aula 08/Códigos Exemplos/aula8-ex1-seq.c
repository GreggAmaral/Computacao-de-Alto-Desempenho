//Aula 09 - Ex2
#include <stdio.h>
#include <mpi.h>
#include "mede_time.h"

int main(int argc, char *argv[])
{
	int	n,n_nos, rank;
	int vetor[100000];
	int i;
	int ocorrencias;
	int elemento;
        
	n = 100000;
	printf("Digite o elemento a ser busacado: ");
	TIMER_CLEAR;
    TIMER_START;
	fflush(stdout);
	scanf("%d",&elemento);
	for(i = 0 ; i < n; i++)
		vetor[i] = (i*3)%100+i%150;

//============== Calculo do numero de ocorrencias em cada rank ================
    ocorrencias=0;
	for(i = 0; i < n; i++){
		if(vetor[i] == elemento)
			ocorrencias++;
	}
	TIMER_STOP;
    printf ("Tempo de execucao: %12.7f\n",TIMER_ELAPSED);
	printf("Ocorrencias =%d\n",ocorrencias);
	fflush(stdout); 

	return 0;
}
