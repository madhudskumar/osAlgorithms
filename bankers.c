#include<stdio.h>
#include<stdlib.h>

int main()
{
	int np,nr;
	int max[10][10],alloc[10][10],p[10],c[10];
	int sum[10],avail[10];
	int i,j,k,z;	

	c[10] = p[10] = sum[10] = 0;
	
	printf("\nEnter the no of process\n");scanf("%d",&np);
	printf("\nEnter the no of resources\n");scanf("%d",&nr);


	printf("\nEnter avaliable resources\n");
	for(i = 0;i < nr; i++)
	{
		printf("\n%d > ",i+1);scanf("%d",&c[i]);
	}

	printf("\nEnter the maximum resources\n");
	for(i = 0;i < np; i++)
	{
		for(j = 0;j < nr; j++)
		{
			scanf("%d",&max[i][j]);
		}
	}

	printf("\nEnter the allocated resources\n");
	for(i = 0; i < np; i++)
	{
		for(j = 0;j < nr; j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}

	printf("\navail vector\n");
	for(j = 0; j < nr; j++)
	{
		for(i = 0; i < nr; i++) sum[j] = sum[j] + alloc[i][j];
		
		avail[j] = c[j] - sum[j];
		
		printf(" %d ",avail[j]);
	}

	for(z = 0; z < np; z++)
	{
		for(i = 0; i< np; i++)
		{
			if(p[i] = 0)
			{
				for(j = 0; j < nr; j++)
				{
					if((max[i][j] - alloc[i][j]) > avail[i]) break;
				}
			}

			if(j == nr)
			{
				p[i] = 1;
				printf("\nProcess %d e & t\n",i + 1);
				printf("\navail vector\n");
				
				for(k = 0; k < nr; k++)
				{
					avail[k] = avail[k] + alloc[i][k];
					alloc[i][k] = 0;

					printf(" %d ",avail[k]);
				}
			}
		}
	}

	for(i = 0; i < np; i++)
	{
		if(p[i] != 1)
		{
			printf("\nUnsafe\n");
			exit(-1);	
		}
	}

	printf("\nSafe state\n");
}
