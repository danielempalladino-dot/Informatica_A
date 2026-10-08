#include<stdio.h>
#include<string.h>
#define N 20


/*
Si scriva una funzione spaccaParola che prende in ingresso una stringa ? e altre variabili che si ritiene
necessario ? e riporta al chiamante una stringa di vocali ed una stringa di altre lettere.
Si invochi la funzione nel main e si stampi no le tre stringhe */

void spaccaParola (char p[], char v[], char c[]);
void stampaParola (char p[], char v[], char c[]);
// dichiarare qui i prototipi delle funzioni


int main()
{
char parola[N] = "bella Info A!";
char vocali[N], altro[N];


// si invochi la funzione spaccaParola
spaccaParola (parola, vocali, altro);
stampaParola (parola, vocali, altro);
// stampare le tre stringhe




return 0;
}

void spaccaParola (char p[], char v[], char c[]) //funzione che divide la stringa in ingresso in due altre stringe: una vocali e l'altra conosnanti
{
	int i = 0, j = 0, k = 0;
	for (i=0; p[i] != '\0'; i++)
	{
		if (p[i] == 'a'|| p[i] == 'e' || p[i] == 'i' || p[i] == 'o' || p[i] == 'u' || p[i] == 'A' || p[i] == 'E' || p[i] == 'I' || p[i] == 'O' || p[i] == 'U')
		{ //controllo per le vocali
			v[j] = p[i];
			j++;
		}
		else if ((p[i]>= 'a' && p[i]<= 'z') || (p[i]>= 'A'&& p[i]<= 'Z'))
		{ //controllo per le consonanti 
			c[k] = p[i];
			k++;
		}
	}
	v[j]='\0';
	c[k]='\0'; //aggiungo il carattere terminatore per entrambe le sringe cosi da essere ben formate
}
void stampaParola(char p[], char v[], char c[])
{
	printf("%s\n", p);
	printf("%s\n", v);
	printf("%s", c);
}
