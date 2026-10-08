#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define L 50
#define N 20
#define M 5
typedef struct{
	char nome[L];
	int anno;
} persona;
typedef struct{
      char nomi_invitati[N][L];
      int numero_invitati;
      int numero_partecipanti;
} ListaInvitati;
int main()
{
	int i, j, k, max;
	ListaInvitati festa;
	festa.numero_partecipanti = 0;
	persona presenti[M];
	//numero invitati 
	do
	{
		printf("Numero di invitati: ");
		scanf(" %d", &max);
		fflush(stdin);
		festa.numero_invitati=max;
	}
	while (max>N);
	//nomi invitati
	for (i=0; i<festa.numero_invitati; i++)
	{
		printf("\nNome e cognome dell'invitato numero %d: ", i+1);
		fgets(festa.nomi_invitati[i], L, stdin);
	}
	//persone presenti
	for (i=0;i<M;i++)
	{
		printf("Persona numero %d:\nNome:",i+1);
		fgets(presenti[i].nome, L, stdin);
		printf("Anno di nascita: ");
		scanf("%d", &presenti[i].anno);
		fflush(stdin);
	}
	//confronto i nomi dei presenti con i partecipanti
	for(i=0;i<festa.numero_invitati; i++)
	{
		for(j=0;j<M;j++)
			if(_stricmp(festa.nomi_invitati[i], presenti[j].nome)==0)
				festa.numero_partecipanti++;
	}
	printf("alla festa si sono presentati %d invitati", festa.numero_partecipanti);	
}

