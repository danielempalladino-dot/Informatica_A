#include <stdio.h>
int main ()
{
	int n, N=10, bin[N], i; 
	do
	{
		printf("Inserisci un numero in base 10 da 0 a 1023: "); //1023 perche è due alla n meno uno
		scanf(" %d", &n);
	}
	while ((n<0) ||(n>2023));
	for(i = N-1; i >=0; i--) //i = n-1 perche corrisponde all'ultima cella dell'array. inoltre parto da i = n-1 cosi che poi l'array posso leggerlo subito al contrario
	{
		bin[i] = n % 2;
		n = n/2;
	}
	for (i=0; i< N; i++)
		printf("%d", bin[i]);
	return 0;
}
