#include <stdio.h>
int main ()
{
	int a, b, c, colonne, righe;
	printf("Fino a che numero vuoi la riga?\n");
	scanf("%d", &righe),
	printf("\nFino a che numero vuoi la colonna?\n");
	scanf("%d",&colonne);
	a = 1;
	b = 1;
	while (b <= colonne)
	{
		while (a <= righe)
		{
			c = a*b;
			if (a==b)
				printf("%d ", c);
			else
				printf("  ");
			a++;
		}
		b++;
		/* i++ --> prima incremento e poi qssegno mentre ++i --> prima assegno e poi incremento */
		a=1;
		printf("\n");	
	}
	printf("\nGrazie per aver utilizzato il programma,\nBuona giornata!");
}
