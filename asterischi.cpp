#include <stdio.h>
int main ()
{
	int l, i, n;
	printf("Inserisci la lunghezza del quadrato: ");
	scanf("%d", &l);
	for (i=1 ; i <= l ; i++)
	{
		for (n=1 ; n <= l ; n++)
		{
			if ((n==1)||(n==l)||(i==1)||(i==l))
			printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}
