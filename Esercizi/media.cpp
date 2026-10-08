#include <stdio.h>
#define N 5
int main ()
{
	int n[N], i, sum = 0, media;
	for (i=0; i<N; i++)
	{
		printf("inserisci un numero: ");
		scanf(" %d", &n[i]);
		sum = sum + n[i];
	}
	media = (sum/N);
	for (i=0; i<N; i++)
	{
		if (n[i]>media)
		printf("+, ");
		else if (n[i]<media)
		printf("-, ");
		else printf("=, ");
	}
}
