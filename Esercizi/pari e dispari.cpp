#include <stdio.h>
#define N 10
int main ()
{
	int n[N], pari[N], dispari[N],i, p=0, d=0, max;
	for (i=0; i<N; i++)
	{
		printf("inserisci un numero: ");
		scanf(" %d", &n[i]);
	}
	for (i=0; i<N; i++)
	{
		if(n[i]%2 == 0)
		{
			pari[p] = n[i];
			p++;
		}
		else 
		{
			dispari[d]= n[i];
			d++;
		}
	}
	//Stampo prima originale, poi pari, poi dispari
	printf("array originale: ");
	for (i=0; i<N; i++)
	printf("%d, ", n[i]);
	printf("\nArray pari: ");
	for(i=0; i<p; i++)
	printf("%d, ", pari[i]);
	printf("\nArray dispari: ");
	for(i=0; i<d; i++)
	printf("%d, ", dispari[i]);
}
	
