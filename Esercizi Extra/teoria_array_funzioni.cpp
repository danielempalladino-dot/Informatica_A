#include <stdio.h>

int LeggiNumero();
{
	int a
	printf("")
	scanf("%d", &a);	
	return a;
}

void stampaarray(int v[], int dim)
{
	int i;
	printf("[")
	for (i=0; i<dim;i++)
			printf("%d "v[i]);
}

void stampaArrayP (int *p, int dim)
{
	int i;
	printf("[")
	for (i=0; i<dim; i++)
		printf("%d", *(p+i)); // p = puntatore al primo elemento, incrmeneto le celle con indice i ottenento cosi un puntatore all'indice i esimo
}
