#include <stdio.h>
#define N 5
int main ()
{
	int n[N], i, j, temp;
	for (i=0; i<N; i++)
	{
		printf("dammi un numero: ");
		scanf(" %d", &n[i]);
	}
	for (j=0; j<N; j++)
	{
		for (i=0; i < N-1; i++)
		if (n[i] > n[i+1])
		{
			temp = n[i + 1];
			n[i + 1] = n[i];
			n[i] = temp;
		}
	}
	printf("\nil tuo minimo e' %d, e il tuo massimo e' %d", n[0], n[N-1]);
}
