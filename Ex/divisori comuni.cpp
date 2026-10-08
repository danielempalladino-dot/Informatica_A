#include <stdio.h>
int main ()
{
	int primo, secondo, i;
	printf("DIVISORI COMUNI;\nInserisci il primo numero: ");
	scanf(" %d", &primo);
	printf("Inserisci il secondo numero: ");
	scanf(" %d", &secondo);
	if (primo>secondo)
	{
		i = primo;
		primo = secondo;
		secondo = i;
	}
	printf("Questi sono i divisori comuni:\n");
	for (i=1; i <= secondo; i++)
	{
		if ((primo % i == 0) && (secondo % i == 0))
		printf("%d ", i);
	}
}
