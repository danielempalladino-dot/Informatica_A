#include <stdio.h>
int main ()
{
	int primo, secondo, i, res;
	printf("Scrivere un programma per il calcolo delle tabelline. Il programma riceve dall’utente due numeri. Il primo corrisponde al numero di cui è necessario calcolare la tabellina mentre il secondo indica la lunghezza della tabellina richiesta.\nInserisci il primo numero: ");
	scanf(" %d", &primo);
	printf("Inserisci il secondo numero: ");
	scanf(" %d", &secondo);
	for (i=1 ; i <= secondo; i++)
	{
		res = i * primo;
		printf("%d ", res);
	}
}
