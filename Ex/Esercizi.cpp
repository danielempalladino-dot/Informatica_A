#include <stdio.h>
#include <math.h>
int main ()
{
	int scelta;
	do 
	{
		printf("--- Menu Principale ---\n");
		printf("1. Anno Bisestile\n2. Celsius - Fahrenheit\n3. Esercizio Somma\n4. Funzione Modulo\n5. Resto Banconote\n6. Equazioni di secondo grado\n0. Esci\n");
		printf("-----------------------\nInserisci la tua scelta: ");
		scanf(" %d", &scelta);
		switch (scelta)
		{
			case 1:
				int anno;
				printf("Dimmi un anno e ti diro' se e' bisestile:\n");
				scanf("%d", &anno);
				if(anno%400 == 0)
				{
					printf("Complimenti! L'anno selezionato e' bisestile\n\n");
					break;
				}
				if (anno%4==0)
				{
					if(anno%100==0)
					{
						printf("Mi dispiace, l'hanno selezionato non e' bisestile\n\n");
						break;
					} 
					else printf("Complimenti! L'anno selezionato e' bisestile\n\n");
					break;
				}
				else printf("Mi dispiace, l'hanno selezionato non e' bisestile\n\n");
				break;
			case 2:
				printf("in che unita di misura hai la temperatura? \n");
				char unit;
				scanf(" %c", &unit);
				if (unit == 'f')
				{
					float f, c;
					printf("che temperatura c'e' in fahrenheit? \n");
					scanf("%f", &f);
					c= ((f-32)*5.0)/9;
					printf("\necco la temperatura in celsius: %.2f C\n\n", c);
					//printf non ha bisogno dell'associazione tramite &, basta semplicemente la virgola 
					break;
				}
				if (unit == 'c')
				{
					float f, c;
					printf("che temperatura c'e' in celsius? \n");
					scanf("%f", &c);
					f= ((9*c)/5.0)+25 ;
					printf("\necco la temperatura in Fahrenheit: %.2f F\n\n", f);
					break;
				}
				else
				{
					printf("unita di misura non riconosciuta!\n\n");
					break;
				}
			case 3:
				int a, b, c, d;
				printf("dimmi i 4 numeri \n");
				scanf("%d%d%d%d", &a, &b, &c, &d);
				//scanf("%d,&d,%d,&d", &a, &b, &c, &d); ATTENZIONE --> non si mettono le virgole quando definisci la tipologia di imput
				a= (a+b)*(c+d);
				printf("\nil risultato e': %d\n\n", a);
				break;
			case 4:
				float n;
				printf("Di che numero vuoi fare il modulo?\n");
				scanf(" %f", &n);
				if (n<0)
				n = -n;
				printf("%.2f\n\n", n);
				break;
			case 5:
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
				printf("\nComunque potresti usare anche il pos!\n\n");
				break;
			case 6:
				float a1,b1,c1,delta,x1,x2;
				printf("inserisci a: ");
				scanf(" %f", &a1);
				printf("\nOra iserisci b: ");
				scanf(" %f", &b1);
				printf("\nOra inserisci c: ");
				scanf(" %f", &c1);
				printf("\n%f\n%f\n%f", a1,b1,c1);
				delta = (b1*b1)-(4*a1*c1);
				printf("\nDelta = %f", delta);
				if (delta >=0)
				{
					if (delta>0)
					{
						x1 = (-b1-sqrt(delta))/(2*a1);
						x2 = (-b1+sqrt(delta))/(2*a1);
						printf("\nx1 = %.2f\nx2 = %.2f\n\n", x1, x2);
						break;
					}
					else 
					{
						x1= (-b1)/(2*a1);
						printf("\nLa tua equazione e' un quadrato:\nx1,2 = %.2f\n\n", x1);
						break;
					}
				}
				printf("\nIl delta e' negativo, non ci sono soluzioni!\n\n");
				break;
			}
			
	}
	while (scelta != 0);
return 0;
}
