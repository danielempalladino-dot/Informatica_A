#include <stdio.h>
int main ()
{
	int menu, a,b,c;
	do 
	{
		printf("--- Menu Principale ---\nScelte:\n1. Somma\n2. Moltiplicazione\n0. Esci\n");
		scanf("%d", &menu);
		if (menu == 1)
		{
			printf("\nDammi i due valori:\n");
			scanf(" %d", &a);
			scanf(" %d", &b);
			a = a+b;
			printf("%d\n\n",a);
		}
		if (menu == 2)
		{
			printf("\nDammi i due valori:\n");
			scanf(" %d", &a);
			scanf(" %d", &b);
			c = a*b;
			printf("%d\n\n", c);
		}
		if (((menu < 0) || (menu >2)))
		{
			printf("\nErrore: Carattere non riconosciuto!");
			return 1;
		}
	}
	while (menu != 0);
	printf("\nGrazie e arrivederci!");
}
