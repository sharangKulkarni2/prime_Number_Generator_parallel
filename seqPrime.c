// sequential code for prime number generation

#include<stdio.h>
#include<math.h>
#include<omp.h>
#include<stdlib.h>
#define N 50000000 //N is the the number upto which, we are generating prime numbers.

int main(){

FILE *fPtr; //writing data to file for furthur plotting graphs
unsigned long i,j;
int flag;
double start = omp_get_wtime(); //openmp function getting wall clock time
double end;  
double eTime; 
for(i=2; i<=N; i++){           
	flag = 0;
	for(j = 2; j<=sqrt(i); j++){
		if((i % j) == 0){
			flag = 1;
			break;
		}
	}
	if(flag==0)
		 continue; //if u want to print prime numbers use printf("%d ", i);
}
end = omp_get_wtime();
eTime = end - start;

fPtr = fopen("seqResult.csv", "a"); // opening a file for writing/appending
if (fPtr == NULL)
    {
        
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have write privilege.\n");
        exit(EXIT_FAILURE);
    }

fprintf(fPtr,"%d, %lf\n",N,eTime); // printing to a file
return 0;
}
