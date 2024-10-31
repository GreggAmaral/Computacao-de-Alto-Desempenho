#include <stdio.h>
#include <mpi.h>
#include <sys/time.h>
#include "mede_time.h"

int tam[50]; 
int A[1200][1200],B[1200][1200],C[1200][1200];
int max,max_final;

int main(int argc, char *argv[]) {
    FILE *f;
    int i, j, k, iter, tamanho_matriz;
  
    f = fopen("tamanho", "r");
    fread(tam,4,50,f);
  
    max_final = 0;

    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    TIMER_CLEAR;
    TIMER_START;

    if (rank == 0) {
        // Processo 0: mestre
        int iter_corrente = 0;
        MPI_Status status;

        // Distribui a primeira iteração para cada processo
        for (int i = 1; i < size; i++) {
            MPI_Send(&iter_corrente, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            iter_corrente++;
        }

        // Recebe resultados e envia novas iterações
        while (iter_corrente < iter) { 
            MPI_Recv(&max, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
            if (max_final < max) {
                max_final = max;
            }
            MPI_Send(&iter_corrente, 1, MPI_INT, status.MPI_SOURCE, 0, MPI_COMM_WORLD);
            iter_corrente++;
        }

        // Recebe resultados finais dos processos restantes
        for (int i = 1; i < size; i++) {
            MPI_Recv(&max, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &status);
            if (max_final < max) {
                max_final = max;
            }
        }

        // Envia mensagem de término
        for (int i = 1; i < size; i++) {
            MPI_Send(&iter_corrente, 1, MPI_INT, i, 1, MPI_COMM_WORLD); // Tag 1 para indicar fim
        }

    } 
    else {
        MPI_Status status;

        FILE *f = fopen("tamanho", "r");
        fread(tam, 4, 50, f);
        fclose(f);

        // Loop principal
        while (1) {
            MPI_Recv(&iter, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

            if (status.MPI_TAG == 1) { // Mensagem de término
                break;
            }

            // Inicializa as matrizes e realiza o cálculo
            tamanho_matriz = tam[iter];
            for(i = 0; i < tamanho_matriz; i++)
                for(j = 0; j < tamanho_matriz; j++){
                    A[i][j] = 1;  
                    B[i][j] = 1;
                    C[i][j] = 0;
                }
            for(i = 0; i < tamanho_matriz; i++)
                for(k = 0; k < tamanho_matriz; k++)
                    for(j = 0; j < tamanho_matriz; j++)
                        C[i][j] = C[i][j] + A[i][k]*B[k][j];

            // Envia o resultado para o processo mestre
            MPI_Send(&max, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }
    }
    MPI_Finalize();

    TIMER_STOP;
    printf ("TEMPO : %12.7f\n",TIMER_ELAPSED );
    return 0;
}