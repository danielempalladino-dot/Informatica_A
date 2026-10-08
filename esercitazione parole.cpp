#include <stdio.h>
#include <string.h> 
#define N 5
typedef char stringa[30];
int main ()
{
	stringa parole[N];
	int i, j, count=0, flag=0, lunghezza;
	for (i=0; i<N; i++)
	{
		printf("Inserisci la parola numero %d: ", i+1);
		fgets(parole[i],30,stdin);
	}
	for (i=0; i<N; i++)
	{
		lunghezza = strlen (parole[i]);
		for(j=0; j<lunghezza-1; j++)
		{
			if (parole[i][j] == 'a')
				count++;
		}
		printf("%d\n", lunghezza);
	}
	printf("Numero di vocali: %d", count);
}

