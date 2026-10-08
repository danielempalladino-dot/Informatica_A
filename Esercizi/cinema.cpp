#include <stdio.h>
#define L 50
#define N 10
typedef struct{
      int anno;
      char genere[L];
      float voto;
} Film;

typedef struct{
      Film films[N];
      int numero_film_in_sala;
      float prezzo_biglietto;
} SalaCinema;

void popolazionefilm(SalaCinema *X);
float calcolaricavo(SalaCinema *X);

int main()
{
	float ricavato;
	int i;
	SalaCinema bicocca;
	printf("Quanti film ci sono nella sala? ");
	scanf("%d", &bicocca.numero_film_in_sala);
	printf("\nChe film ci sono?");
	popolazionefilm(&bicocca);
	ricavato = calcolaricavo(&bicocca);
	printf("I guadagni del cinema questa sera sono %.2f", ricavato);
	
	
	
}

void popolazionefilm(SalaCinema *X)
{
	int i;
	for(i=0; i < X->numero_film_in_sala; i++)
	{
		printf("\nFilm numero %d:\nAnno di pubblicazione: ",i+1);
		scanf(" %d", &X->films[i].anno);
		fflush(stdin);
		printf("Genere: ");
		fgets(X->films[i].genere, L, stdin);
		fflush(stdin);
		printf("Voto: ");
		scanf("%f",&X->films[i].voto);
	}
}

float calcolaricavo(SalaCinema *X)
{
	int i;
	float ricavo=0;
	printf("Quanto costa il biglietto? ");
	scanf("%f", &X->prezzo_biglietto);
	for(i=0; i<X->numero_film_in_sala; i++)
	{
		ricavo = ricavo + (X->films[i].voto * 10 * X->prezzo_biglietto);
	}
	return ricavo;
}
