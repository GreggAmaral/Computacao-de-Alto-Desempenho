#include <stdio.h>
int A[2000];
int B[2000];
int C[2000];
int X[2000];
void tar1()
{int i,j;
   A[0]=X[0]; 
   for (i=1;i<2000;i++){
      A[i]=A[i-1]%1000+X[i] * 5;
      for(j=0;j<2000;j++)
         A[i]=A[i]%100+A[i-1];
   }
printf("FIM tar1\n");
fflush(stdout);
}
void tar2()
{  int i,j;
   B[0]=1;
   for (i=1;i<2000;i++){
      B[i]=B[i-1]%1000+A[i-1]*3;
      for(j=0;j<2000;j++)
         B[i]=B[i]%100+B[i-1];
   }
printf("FIM tar2\n");
fflush(stdout);
}
void tar3()
{ int i,j;
   C[0]=1;
   for (i=1;i<2000;i++){
      C[i]=C[i-1]%1000+A[i-1] * 2;
      for(j=0;j<2000;j++)
         C[i]=C[i]%100+C[i-1];
   }
printf("FIM tar3\n");
fflush(stdout);
}

void main()
{int i;
   for (i=0;i<2000;i++)
      X[i]=i+2;
   tar1();
   tar2();
   tar3();
   printf("B[0]=%d B[1]=%d B[500]=%d B[1999]=%d \n",B[0],B[1],B[500],B[1999]);  
   printf("C[0]=%d C[1]=%d C[500]=%d C[1999]=%d \n",C[0],C[1],C[500],C[1999]);
}      
  
    
