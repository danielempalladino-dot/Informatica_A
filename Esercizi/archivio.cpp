#include <stdlib.h>
#include <stdio.h>
#define N 5
typedef struct 
{
	int eta;
	int altezza;
	int peso;
}Dati_Archivio;

int main ()
{
	int i;
	Dati_Archivio X, persone [N]; //array di struttre
	for (i=0; i<N; i++)//popolo l'array di strutture --> riempo i tre campi
	{
		do
		{
			printf("INSERISCI ETA: ");
			scanf(" %d", &persone[i].eta);
		}
		while (persone[i].eta<0); //condizione che sia un numero e non un carattere
		//poi faccio le stesse cose per l'altezza e il peso		
		do
		{
			printf("\nINSERISCI ALTEZZA: ");
			scanf(" %d", &persone[i].altezza);
		}
		while (persone[i].altezza<0);
		do
		{
			printf("\nINSERISCI PESO: ");
			scanf(" %d", &persone[i].peso);
		}
		while (persone[i].peso<0); 
	}
	for (i=0; i<N; i++)
	{
		printf("Persona %d, eta = %d, aktezza = %d, peso= %d kg", i+1, persone[i].eta, persone[i].altezza, persone[i].peso);
	}
	
}
