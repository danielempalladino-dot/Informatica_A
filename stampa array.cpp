#include <stdio.h>
#define N 5
int main ()
{
	int n[N], i, sum = 0, media;
	for (i=0; i<N; i++)
	{
		printf("inserisci un numero: ");
		scanf(" %d", &n[i]);
	}
	for (i=N-1; i>=0; i--)
	printf("%d, ", n[i]);
}
