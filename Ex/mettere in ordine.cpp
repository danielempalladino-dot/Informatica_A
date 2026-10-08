#include <stdio.h>
#define N 5

int main ()
{
	char stringa [N];
	int i,j, flag = 0;
	for (i=0; i<N; i++)
	{
		do
		{
			printf("inserisci il carattere: ");
			scanf(" %c", &stringa[i]);
		}
		while (!((stringa[i] >= 'a') && (stringa[i] <= 'z')));
	}
	for (j=0; j<N; j++)
	{
		for (i=0; i < N-1; i++)
		if (stringa[i] > stringa[i+1])
		{
			flag = 1;
		}
	}
	if (flag == 0)
	printf("sono in ordine");
	if (flag == 1)
	printf("non sono in ordine");
}
