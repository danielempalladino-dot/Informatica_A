/*Costruite un programma per gestire una lista di film. Per immagazzinare i film dovete usare la seguente struttura:

typedef struct _movie {
                char title[MAX_LEN];
                char type[MAX_LEN]; // Ad esempio: horror, action . . .
                int year;                       // L’anno in cui è stato girato il film
} movie;

Per immagazzinare i film che vengono inseriti dall’utente dovete usare una lista. In questo caso, il dato contenuto in ogni nodo della lista non 
sarà un semplice char o un int, ma una struttura di tipo movie. Nella lista i nuovi film devono essere inseriti in modo ordinato 
a seconda dell’anno in cui è stato girato il film (prima i film più vecchi poi quelli più nuovi).

Per questo progetto implementate quattro funzioni che devono essere richiamate opportunamente nel main:

•     lista add(lista listaFilm) // chiede i dati per un nuovo film, lo aggiunge alla lista listaFilm  nella posizione corretta, 
e restituisce la lista aggiornata.

•     void print(lista listaFilm) // stampa la lista dei film.

•     lista search(lista listaFilm, char * title) // cerca un film nella lista in base al titolo

•     lista remove(lista listaFilm, lista film) // rimuove un film dalla lista.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 50
typedef struct _movie {
                char title[MAX_LEN];
                char type[MAX_LEN]; // Ad esempio: horror, action . . .
                int year;                       // L’anno in cui è stato girato il film
} movie;

typedef struct El
{
	movie film;
	struct El *next;
}Nodo;

typedef Nodo *Lista;

movie aggiungiFilm();
Lista add(Lista LitstaFilm);

int main()
{
	Lista Film = NULL;
	for(int i = 0; i<3; i++)
	{
		Film = add(Film);
	}
	printf("%s," ,Film->next->next->film.title);

}
movie aggiungiFilm()
{
	movie film;
	printf("Inserisci il titolo: ");
	fgets(film.title, MAX_LEN, stdin);
	film.title[strcspn(film.title, "\n")] = '\0';
	printf("Inserisci tipologia: ");
	fgets(film.type, MAX_LEN, stdin);
	film.type[strcspn(film.type, "\n")] = '\0';
	printf("Inserisci anno di pubblicazione: ");
	scanf("%d", &film.year);
	fflush(stdin);
	return film;
}
Lista add(Lista head)
{
	Lista pnew = NULL, curr = head, prec = NULL;
	pnew = (Lista)malloc(sizeof(Nodo));
	pnew->film = aggiungiFilm();
	pnew->next = NULL;
	while(curr != NULL && pnew->film.year >= curr->film.year)
	{
		prec = curr;
		curr = curr->next;
	}
	pnew->next = curr;
	if(prec!=NULL)
	{
		prec->next = pnew;
		return head;
	}
	else
		return pnew;
}

