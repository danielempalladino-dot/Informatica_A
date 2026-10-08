#include <stdio.h>
#include <string.h>
int main()
{
	char parola[30], carattere = 'a';
	int lunghezza, i, contatore[26]={0}, flag = 0, min=0, max=0;
	do
	{
		flag = 0;
		printf("Inserisci parola: ");
		scanf(" %s", parola);
		lunghezza = strlen(parola);
		for (i=0; i<lunghezza; i++)
			if(!((parola[i]>='A'&& parola[i]<='Z')|| (parola[i]>= 'a' && parola[i]<='z')))
				flag = 1;
	}
	while (flag == 1);
	for (i=0; i<lunghezza;i++)
	{
		if(parola[i]>='A'&& parola[i]<='Z')
			parola [i]= parola[i]+32;
		contatore[parola[i]-97]++;
	}
	for (i=0; i<25; i++)
	{
		if (contatore[i]!=0)
		{
			printf("carattere %c: %d\n", carattere, contatore[i]);
		
		}
			carattere++;
	}
	//ottengo il grado della parola
	for (i=0; i<26;i++)
	{
		if(contatore[i]>max)
			max = contatore[i];
		if(contatore[i] == 1 )
			min = contatore[i];
		if (contatore[i] > 0 && (min == 0 || contatore[i] < min))
			min = contatore[i];
	}
	printf("\nGRADO DELLA PAROLA:g = %d; G = %d", min, max);
}


