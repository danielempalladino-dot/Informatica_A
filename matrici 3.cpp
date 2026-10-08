#include <stdio.h>
#define N 4
int main()
{
	int M[N][N]={1,2,0,1,0,3,0,2,0,3,1,2,1,1,2,4};
	int i,j; 
	for(i=0;i<N;i++)
	{
		printf("\n");
		for(j=0;j<N;j++)
			printf("[%d]", M[i][j]);
	}
}
