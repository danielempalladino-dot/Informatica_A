#include <stdio.h>
int main ()
{
	float prezzo, sconto;
	printf("Inserisci il prezzo;\n");
	scanf("%f", &prezzo);
	printf("\nInserisci lo sconto:\n");
	scanf("%f", &sconto);
	if ((sconto<0)||(sconto>100))
	{
		printf("sconto non valido!");
		return 1;
	}
	prezzo = prezzo - (prezzo *(sconto/100.00));
	printf("\nEcco il tuo prezzo scontato: %.2f", prezzo);
	return 0;
}
