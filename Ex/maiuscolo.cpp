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
	for (i=0; i<N; i++)
	{
		stringa[i] = stringa[i]-32;
		printf("%c, ", stringa[i]);
	}
}
	
