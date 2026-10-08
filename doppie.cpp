#include <stdio.h>
#include <string.h>
#define N 30
typedef char stringa[N];
int main ()
{
	stringa parola;
	int i, j, lunghezza, flag;
	printf("inserisci parola: ");
	scanf(" %s", parola);
	lunghezza = strlen(parola);
	do
	{
		flag = 1;
		for(i=0;i<lunghezza;i++)
		{
			if (parola[i] == parola [i+1])
			{
				for (j=0;j<lunghezza-i-2;j++)
					parola[i+j] = parola[i+j+2];
				parola[i+j] = '\0'; //carattere terminatore sulla stringa
				flag = 0;
				
			}
		}
	}
	while (flag == 0);
	printf("%s", parola);
}
