#include<stdio.h>
#include<math.h>
#include<omp.h>
#include<stdlib.h>
#define N 50000000

int main(){
FILE *fPtr;
unsigned int i,j;
int flag;
double start = omp_get_wtime();  
double end;  
double eTime;

#pragma omp parallel num_threads(2000) 
{
#pragma omp for schedule(static, 1) private(i,j,flag) // refer http://jakascorner.com/blog/2016/06/omp-for-scheduling.html
for(i=2; i<=N; i++){
	//printf("i %d working on %d\n ", omp_get_thread_num(), i);
	flag = 0;
	for(j = 2; j<=sqrt(i); j++){
		if((i % j) == 0){
			flag = 1;
			break;
		}
	}
	if(flag==0)
		continue; // or printf("%d ", i);
}
}
end = omp_get_wtime();
eTime = end - start;

fPtr = fopen("parallelResult.csv", "a");
if (fPtr == NULL)
    {
        
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have write privilege.\n");
        exit(EXIT_FAILURE);
    }

fprintf(fPtr,"%lu, %lf\n",N,eTime);
return 0;
}
