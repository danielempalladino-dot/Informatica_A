#include <stdio.h>
#include <string.h>
int main()
{
	int i, j = 0, flag = 0, lunghezza;
	char parola [30];
	printf("Dimmi la parola: ");
	scanf("%s", parola);
	i = strlen(parola)-1;
	lunghezza = i/2;
	for (j=0; j<lunghezza && flag == 0;j++)
		if(!(parola[j] == parola[i-j])) 
			flag = 1;
	printf("%d", flag);
}
