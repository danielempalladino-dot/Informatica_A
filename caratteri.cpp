#include <stdio.h>
int main ()
{
	char primo, secondo, temp;
	printf("Scrivere un programma in linguaggio C che, letti due caratteri minuscoli dallo standard input, stabilisce quale dei due viene prima e quale dopo in ordine alfabetico e stampi l’intera porzione di alfabeto tra i due.\nInserici il primo carattere: ");
	scanf(" %c", &primo);
	printf("Inserisci il secondo carttrere: ");
	scanf(" %c", &secondo);
	if (!((primo >= 'a') && (primo <= 'z'))||!((secondo >= 'a')&&(secondo <= 'z')))
		{
			printf("carattere non riconosciuto");
			return 1;
		}
	if (primo > secondo)
	{
		temp = primo;
		primo = secondo;
		secondo = temp;
	}
	while (primo <= secondo)
	{
		printf("%c ", primo);
		primo++;
	}
	return 2;
}
