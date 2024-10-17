//programa correto usando simple lock
#include <stdio.h>
#include <omp.h>

int A,B,X,Y;
omp_nest_lock_t sem;

int main()
{ 
	printf("INICIO\n");

	omp_init_nest_lock(&sem);
	omp_set_nest_lock(&sem);
	omp_set_num_threads(2);

	#pragma omp parallel sections
	{
		#pragma omp section
		{
			int i;
			printf("secao 1\n");
    
			//for (i = 0; i < 1000000; i++){
			for (i = 0; i < 10; i++){
				printf("a");
				fflush(stdout);
			}
     
			A = 9;
			omp_unset_nest_lock(&sem);

			for (i = 0 ;i < 10; i++){
				printf("b");
				fflush(stdout);
			}

     		B = 15;
			printf("B=%d\n",B);
			fflush(stdout);
			omp_unset_nest_lock(&sem);
		}

		#pragma omp section 	
		{ 
			printf("secao 2\n");
			fflush(stdout);
			omp_set_nest_lock(&sem);
			X = A + 1;
			omp_set_nest_lock(&sem);
			printf("B=%d\n",B);
			fflush(stdout);
			Y = B + 1;
		}
	}
 
	omp_destroy_nest_lock_(&sem);
	printf("X=%d    Y=%d \n",X,Y);  //resultado correto: X=10   Y=16
	fflush(stdout);
	printf("FIM\n");
}
