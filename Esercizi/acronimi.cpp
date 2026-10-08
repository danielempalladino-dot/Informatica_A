#include <stdio.h>
#include <string.h>
#define N 100
typedef char stringa[N];
int main ()
{
	stringa parola, acronimo;
	int i, j=1, lunghezza;
	printf("Inserisci la frase: ");
	fgets(parola, 100, stdin);
	lunghezza = strlen(parola);
	acronimo[0] = parola[0];
	for (i=0; i<lunghezza; i++)
	{
		if ((parola[i]>='A' && parola[i]<='Z')||(parola[i]>='a' && parola[i]<='z'));
		else
		{
			acronimo[j] = parola[i+1];
			j++;
		}
	}
	acronimo[j]=parola[lunghezza];
	lunghezza = strlen(acronimo);
	for(j=0;j<lunghezza;j++)
	acronimo[j] = acronimo[j]-32;
	printf("%s", acronimo);
}
