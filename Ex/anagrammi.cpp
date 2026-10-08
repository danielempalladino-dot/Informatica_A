#include <stdio.h>
#include <string.h>
#define N 300
#define MAX_ASCII 256
int main()
{
	char s1[N], s2[N];
	int cont1[MAX_ASCII] = {0}, cont2[MAX_ASCII] = {0}, i, diversi = 0;
	
	printf("INSERIRE LA PRIMA PAROLA: ");
	scanf("%s",s1); fflush(stdin); // per purire l'imput e necessario f flush!
	int len1 = strlen(s1);
	
	printf("INSERIRE LA SECONDA PAROLA: ");
	scanf("%s", s2); fflush(stdin);
	int len2 = strlen(s2);
	//confronto le stringe in ricerca di anagrammi
	if (len1 != len2)
	printf("non sono anagrammi!");
	else 
	{
		for(i=0; i < len1; i++) //tanto len1 = len2
		cont1[s1[i]]++;
		cont2[s2[i]]++; //sto contanto il numero di volte che una lettera compare --> simile esempio dadi --> se s1 = a --> aumentera il 
		//98 casella dell'array cont che nella tabella ascii corrisponde alla a
	}
	for(i=0; i<MAX_ASCII && diversi == 0; i++) // per verificare che siano uguali uso una flag --> ne basta uno diverso
	{
		if (cont1[i] != cont2[i])
		diversi = 1;
	}
	if(diversi == 1)
	printf("NON SONO ANAGRAMMI");
	else printf("SONO ANAGRAMMI");
}
