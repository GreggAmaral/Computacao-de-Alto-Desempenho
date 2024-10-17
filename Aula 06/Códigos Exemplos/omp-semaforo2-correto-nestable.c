//programama usando simple lock
//ERRADO: em algumas execuções ocorre travamento
//ERRO: múltiplos locks pela mesma thread sem ter ocorrido unlock.
#include <stdio.h>
#include <omp.h>

int A,B,C;
omp_nest_lock_t sem;

int main()
{ 
	printf("INICIO\n");

	omp_init_nest_lock(&sem);
	omp_set_num_threads(2);
        A=0;
        B=0;
        C=0;
	#pragma omp parallel sections  shared(A)
	{
		#pragma omp section
		{
			int i;
			printf("secao 1\n");
	  		omp_set_nest_lock(&sem);
                        A++; 
	  		omp_set_nest_lock(&sem);
                        B++; 
	  		omp_set_nest_lock(&sem);
                        C++; 
			omp_unset_nest_lock(&sem);
			omp_unset_nest_lock(&sem);
			omp_unset_nest_lock(&sem);
                        
		}

		#pragma omp section 	
		{ 
			printf("secao 2\n");
			fflush(stdout);
	  		omp_set_nest_lock(&sem);
                        A++; 
			omp_unset_nest_lock(&sem);
		}
	}
 
	omp_destroy_nest_lock(&sem);
	printf("A=%d    B=%d  C=%d\n",A,B,C);  //resultado correto: A=2 B=1  C=1
	fflush(stdout);
	printf("FIM\n");
}
