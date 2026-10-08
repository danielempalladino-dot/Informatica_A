#include <stdio.h>
#include <string.h>
#define N 5
typedef char stringa [30];
int main()
{
	int i, j, lunghezza, flag, count;
	stringa parole[N];
	for (i=0;i<N;i++)
	{
		printf("Inserisci la parola numero %d: ", i+1);
		scanf(" %s", parole[i]);
	}
	for (i=0; i<N; i++)
	flag = 1;
	lunghezza = strlen (parole[i]);
	for (j=0; j<lunghezza; j++)
	{
		if (parole [j][i] == '\0')
			flag = 0;
		if (parole [1][1]== 'a')
			count++;
	}
	printf("Numero delle vocali: %d", count);
}
