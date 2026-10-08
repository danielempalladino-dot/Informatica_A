#include <stdio.h>
int calcolatore ();
int main () 
{	
calcolatore ();
}
//Problema di approssimazione --> per alcune cifre si perdono i centesimi
//il programma ha un errore di +- 1 centesimo
int calcolatore ()
	{
		int prezzo, prezzoc, rimanente, rimanentec;
		int n50, n20, n10, n5, n2, n1, n050, n020, n010, n005, n002, n001, n100;
		printf ("Quanto devi pagare?\nEuro:");
		scanf ("%d", &prezzo);
		printf("Centesimi:");
		scanf("%d", &prezzoc);
		n100 = prezzo / 100;
		rimanente = prezzo - (n100*100);
		n50 = rimanente / 50;
		rimanente = rimanente - (n50*50);
		n20 = rimanente / 20;
		rimanente = rimanente - (n20*20);
		n10 = rimanente / 10;
		rimanente = rimanente - (n10*10);
		n5 = rimanente / 5;
		rimanente = rimanente - (n5*5);
		n2 = rimanente / 2;
		rimanente = rimanente - (n2*2);
		n1 = rimanente / 1;
		rimanente = rimanente - (n1*1);
		n050 = prezzoc / 50;
		rimanentec = prezzoc - (n050*50);
		n020 = rimanentec / 20;
		rimanentec = rimanentec - (n020*20);
		n010 = rimanentec / 10;
		rimanentec = rimanentec - (n010*10);
		n005 = rimanentec / 5;
		rimanentec = rimanentec - (n005*5);
		n002 = rimanentec / 2;
		rimanentec = rimanentec - (n002*2);
		n001 = rimanentec;
		printf("\nil totale e' di: %d.%d euro. \nil modo migliore di pagare e' usando:\n", prezzo, prezzoc);
		if(n100>0)
		{
			printf("%d banconote da 100 Euro", n100);
		}
		if (n50> 0)
		{
			printf("%d banconote da 50 Euro", n50);
		}
		if(n20>0)
		{
			printf("\n%d banconote da 20 Euro", n20);
		}
		if (n10> 0)
		{
			printf("\n%d banconota da 10 Euro", n10);
		}
		if (n5> 0)
		{
			printf("\n%d banconota da 5 Euro", n5);
		}
		if (n2> 0)
		{
			printf("\n%d monete da 2 Euro", n2);
		}
		if (n1> 0)
		{
			printf("\n%d moneta da 1 Euro", n1);
		}
		if (n050> 0)
		{
			printf("\n%d moneta da 50 Centesimi", n050);
		}
		if (n020>0)
		{
			printf("\n%d monete da 20 Centesimi", n020);
		}
		if (n010>0)
		{
			printf("\n%d moneta da 10 Centesimi", n010);
		}
		if (n005>0)
		{
			printf("\n%d moneta da 5 Centesimi", n005);
		}
		if (n002>0)
		{
			printf("\n%d monete da 2 Centesimi", n002);
		}
		if (n001>0)
		{
			printf("\n%d moneta da 1 Centesimi", n001);
		}
	printf("\nComunque potresti usare anche il pos!");
		return 0;
	}
