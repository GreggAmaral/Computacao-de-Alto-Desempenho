#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){
    
    int	n,n_nos, rank;
    MPI_Status status;
	int vetor[100000];
	int i, k, inicio;
	int ocorre_parcial, ocorre_total, ocorrencias;
	int elemento;

	printf("Digite o elemento a ser busacado: ");
	fflush(stdout);
	scanf("%d",&elemento);

    MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &n_nos);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        
	n = 100000;
    k = n / n_nos;
	inicio = rank * k;
	
	for(i = 0 ; i < n; i++)
		vetor[i] = (i*3)%100+i%150;

    // Divisao do vetor para todos os ranks 
    if (rank == 0){
		for(i = inicio; i < n; i++)
			vetor[i] = (i*3)%100+i%150;

		for (i = 1; i < n_nos; i++){
			MPI_Send(&vetor[k*i],k,MPI_INT,i,10,MPI_COMM_WORLD);
		}
	}

	else {
		MPI_Recv(vetor,k,MPI_INT,0,10,MPI_COMM_WORLD,&status);

	}

//============== Calculo do numero de ocorrencias em cada rank ================
    ocorrencias=0;

	for(i = 0; i < n; i++){
		if(vetor[i] == elemento)
			ocorrencias++;
	}
    
    // Recepcao das somas parciais no rank 0
    if (rank == 0){
		ocorre_total = ocorre_parcial;
          
		for(i = 1; i < n_nos; i++){
			MPI_Recv(&ocorrencias,1,MPI_INT,MPI_ANY_SOURCE,11,MPI_COMM_WORLD,&status);
			ocorre_total += ocorrencias;
		}
           
	}

	else
		MPI_Send(&ocorre_parcial,1,MPI_INT,0,11,MPI_COMM_WORLD);

    MPI_Finalize();
	printf("Ocorrencias=%d\n ",ocorrencias);
	fflush(stdout);
	return 0;
}