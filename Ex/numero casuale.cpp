#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
	srand(time(0));
	int x , guess;
	x = rand() % 101;
	printf("Inserisci un numero da 0 a 100: ");
	scanf(" %d", &guess);
	while (!(guess == x))
	{
		if (guess > x)
		printf("Il numero da indovinare e' minore di %d \n", guess);
		else printf("Il numero da indovinare e maggiore di '%d \n", guess);
		printf("Inserisci un altro numero: ");
		scanf(" %d", &guess);
	}
	printf("Complimenti hai vinto: il numero era %d", x);
}
