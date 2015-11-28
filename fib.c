#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main(int argc, char * const argv[])
{
	int fib[25] = {0};
	int i,j,n;
	int tmp,temp;

	printf("\nEnter the number range\n");
	 scanf("%d",&n);

	omp_set_num_threads(2);

	#pragma omp parallel
	{
		printf("\nNumber of allocated threads %d\n",omp_get_num_threads());
		
		#pragma omp parallel for
		for(i = 0;i < n; i++){
			printf("\nThread number for calculating %d\n",omp_get_thread_num());

			tmp = rand()%24;
			
			#pragma omp critical
			{
				for(j = 0;j < tmp; j++)
				{
					fib[0] = fib[1] = 1;
					
					for(temp = 2;temp < tmp;temp++) fib[temp] = fib[temp - 1] + fib[temp - 2];
				}
			}
		}
		
		printf("\nThread number for printing %d\n",omp_get_thread_num());
		for(i = 0;i < tmp;i++) printf(" %d ",fib[i]);
		
		printf("\n\n");
	}
}
