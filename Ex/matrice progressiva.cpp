#include <stdio.h>
#define N 3
int main()
{
	int i, j, cont = 1, mat[N][N]={0};
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			mat[i][j]= cont;
			cont++;
		}
	}
	for(i=0; i<N; i++)
	{
			printf("\n");
			for(j=0;j<N;j++)
				printf("[%d] ", mat[i][j]);
	}
	printf("\n");
	for (i=0;i<N;i++)
	{
		printf("\n");
		for(j=0;j<N;j++)
		{
			if(j>i)
			{
				mat[i][j] = mat[i][j]+mat[j][i];
				printf("[%d]", mat[i][j]);
			}
			else if(j==i)
				printf("[%d]", mat[i][j]);
			else 
			{
				mat [i][j]=0;
				printf("[%d]", mat[i][j]);
			}
		}
	}
}
