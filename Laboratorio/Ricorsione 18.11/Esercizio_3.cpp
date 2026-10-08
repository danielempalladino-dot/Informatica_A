/*Si scriva una funzione RICORSIVA che, data una stringa in input, rimuova i caratteri che non sono lettere minuscole. Ad esempio, se la funzione riceve la stringa:

"Oggi, dopo l'orale, ho preso 30 nell'esame di Informatica A"

questa verrà trasformata in

"ggidopoloralehopresonellesamedinformatica"*/
#include <stdio.h>
#define N 100
void rimuoviCaratteri (char s[], int i);
int main()
{
	char s[N];
	int i=0;
	fgets(s, N, stdin);
	rimuoviCaratteri(s, i);
	printf("%s", s);
}
void rimuoviCaratteri (char s[], int i)
{
	if (s[i]=='\0')
		return;
	if (s[i]<'a'||s[i]>'z')
	{
		int j=i;
		for(j;s[j]!= '\0'; j++)
			s[j]=s[j+1];
		i--;
	}
	rimuoviCaratteri(s, i+1);
}
