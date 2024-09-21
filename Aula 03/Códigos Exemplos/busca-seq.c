/* #define IMPRIME 1 */
/*multiplicacao de matrizes: outer-product*/
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include "mede_time.h"
#include <stdlib.h>

int SIZE;

int a[2000][2000];
int x;
int ocorrencias;
/*inicia matriz*/
void init_matrix()
  { 
     int i,j;
      for(i=0;i<SIZE;i++) {  
       for (j=0;j<SIZE;j++)
         a[i][j]=i*j;
      }
  }

/*busca*/
void busca()
  {
      int i,j,k;
      ocorrencias=0;
      for (i=0;i< SIZE;i++) {
         for (j=0;j<SIZE;j++){
            if (a[i][j] == x){
              ocorrencias++; 
            }
         }
       }
  }

 
void main(argc, argv)
int argc;
char **argv;
{

  if (argc>1) { 
    SIZE = atoi(argv[1]);
    printf("Matriz %dx%d\n",SIZE,SIZE);
  }
  else {
    printf("Tamanho da matriz (100 ou 1000 ou 2000): ");
    scanf("%d",&SIZE);
  }
  printf("digite um numero de 0 a 9999:");
  scanf("%d",&x);
  printf("%d\n",x); 
  init_matrix();
  TIMER_CLEAR;
  TIMER_START; 
  busca();
  TIMER_STOP;
  printf ("TEMPO [%d]: %12.7f\n",SIZE,TIMER_ELAPSED );
  printf("NUMERO DE OCORRENCIAS=%d\n",ocorrencias);
}

