#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main()
{
	int i, j, k, max=0, contatore[26]={0};
	char M[N][N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            M[i][j] = 'A' + rand() % 26;
	for(i=0;i<N;i++)
	{
		printf("\n");
		for(j=0;j<N;j++)
		{
			printf("[%c] ", M[i][j]);
			k=M[i][j]-65;
			contatore[k]++;
		}
	}
	printf("\n");
	for(i=0;i<26;i++)
	{
		if(contatore[i]>=max)
		{
			max=contatore[i];
			j=i;
		}
	}
	printf("La lettera piu frequente è %c, presente %d volte.", j+65, max);
}
