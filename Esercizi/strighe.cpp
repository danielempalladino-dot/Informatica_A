#include <stdio.h>
#include <string.h>
#define N 100
int main()
{
	char txt[N], res[N];
	int i, j=1, lunghezza;
	printf("Inserisci testo: ");
	fgets(txt,N,stdin);
	res[0] = txt[0];
	lunghezza = strlen(txt);
	printf("%d", lunghezza);
	for (i=0; i<lunghezza; i++)
		if (txt[i] == ' ')
		{
			res[j]=txt[i-1];
			j++;
			res[j]=txt[i+1];
			j++;
		}
	res[j]=txt[lunghezza-2];
	res[j+1]= txt[lunghezza - 1];
	printf("%s",res);
}
