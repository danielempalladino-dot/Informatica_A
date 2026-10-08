#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

typedef char Stringa[N];

typedef struct 
{
	Stringa Nome;
	float prezzo;
	int vegano;
}Piatto;

typedef struct El{
	Piatto p;
	struct El *next;
}Nodo;

typedef Nodo *Lista;

Lista popolaMenu();
void visualizzaPiatti(Lista);
Lista soloVegan(Lista);
Lista menuEconomico(Lista, float);


int main()
{
	Lista Menu = popolaMenu();
	visualizzaPiatti(Menu);
	Menu = soloVegan(Menu);
	printf("\n\n");
	visualizzaPiatti(Menu);
	printf("\n\n");
	Menu = popolaMenu();
	Menu = menuEconomico(Menu, 8);
	visualizzaPiatti(Menu);
}

Lista InsInFondo(Lista lista, Stringa Piatto, float prezzo, int vegano)
{
	Lista punt;
	if( lista==NULL ) 
	{
		punt = (Lista)malloc( sizeof(Nodo));
		punt->next = NULL; 
		strcpy(punt->p.Nome, Piatto);
		punt->p.prezzo = prezzo;
		punt->p.vegano = vegano;
		return punt;
	}
	else 
	{ 
		lista->next = InsInFondo(lista->next, Piatto, prezzo, vegano);
		return lista;
	}
}


Lista popolaMenu()
{
	Lista head = NULL;
	head = InsInFondo(head, "penne al ragu", 5.50, 1);
	head = InsInFondo(head, "tofu", 10, 0);
	head = InsInFondo(head,"maiale", 7, 1);
	head = InsInFondo(head,"cornetto vegano", 3, 0);
	head = InsInFondo(head,"cereali", 8, 0);
	head = InsInFondo(head,"uovo", 5, 1);
	head = InsInFondo(head,"carbonara", 13, 1);
	return head;
}
void visualizzaPiatti(Lista head)
{
	//caso base
	if(head == NULL)
	{
		printf("|");
		return;
	}
	//funzione
	printf("%s - %.2f$", head->p.Nome, head->p.prezzo);
	if(!head->p.vegano)
		printf(" (vegano)");
	printf("\n");
	//passo ricorsivo
	visualizzaPiatti(head->next);
}

Lista soloVegan(Lista head)
{
	if(head==NULL)
		return head;
	head->next = soloVegan(head->next);
	if(head->p.vegano) //se non è vegano
	{
		Lista temp = head->next;
		free(head);
		return temp;
	}
	return head;
}

Lista menuEconomico(Lista head, float prezzo)
{
	if(head==NULL)
		return head;
	head->next = menuEconomico(head->next, prezzo);
	if(head->p.prezzo<prezzo) //se supera il prezzo
	{
		Lista temp = head->next;
		free(head);
		return temp;
	}
	return head;
}
