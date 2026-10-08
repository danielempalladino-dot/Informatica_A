#include <stdio.h>
#define N 3
int main()
{
	int i, j, mat[N][N];
	for(i=0; i<3; i++)
		for(j=0;j<3;j++)
			scanf("%d", &mat[i][j]);
	for(i=0; i<3; i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
			printf("[%d] ", mat[i][j]);
	}
	printf("\n");
	for(i=0; i<3; i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			if(mat[i][j]%2==0)
				mat[i][j] = mat[i][j]/2;
			printf("[%d]", mat[i][j]);
		}
	}
}
//fallo con le funzioni se puoi come allenamento.
