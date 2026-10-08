#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
typedef char Tipo[N];


typedef struct ndP{
    float costo;
    int tavolo;
    Tipo nome;
    struct ndP* next;
} Piatto;


typedef Piatto* ListaP;


typedef struct ndT{
    int tavolo;
    ListaP ordiniTavolo;
    struct ndT* next;
} Tavolo;
typedef Tavolo* ListaT;


ListaP InsInFondoPiatto(ListaP lista, float costo, int tavolo, Tipo nome);
ListaT InsTavolo(ListaT head, ListaP piatto);
void VisualizzaListaP(ListaP lista);
ListaP costruisci();
void organizzaPerTavoli1(ListaT *tavolo, ListaP head);
ListaT organizzaPerTavoli(ListaP head);
void VisualizzaTavoli(ListaT head);

int main()
{
    ListaP ordini = costruisci();
    ListaP temp;
    ListaT tavoli = NULL;
    VisualizzaListaP(ordini);
    tavoli = organizzaPerTavoli(ordini);
    VisualizzaTavoli(tavoli);
    return 0;
}


// Sviluppare qui le funzioni richieste

void VisualizzaTavoli(ListaT head)
{
	if(head == NULL)
		return;
	printf("---TAVOLO ID: %d---\n", head->tavolo);
	VisualizzaListaP(head->ordiniTavolo);
	VisualizzaTavoli(head->next);
}

ListaT organizzaPerTavoli(ListaP head)
{
	ListaT comanda = NULL;
	organizzaPerTavoli1(&comanda, head);
	return comanda;
}

ListaT InsTavolo(ListaT head, ListaP piatto)
{
	if(head == NULL)
	{
		ListaT pnew = (ListaT)malloc(sizeof(Tavolo));
		pnew->tavolo = piatto->tavolo;
		pnew->ordiniTavolo = NULL;
		pnew->ordiniTavolo = InsInFondoPiatto(pnew->ordiniTavolo, piatto->costo, piatto->tavolo, piatto->nome);
		pnew->next = NULL;
		return pnew;
	}
	if(head->tavolo < piatto->tavolo)
	{
		head->next = InsTavolo(head->next, piatto);
		return head;
	}
	if(head->tavolo == piatto->tavolo)
	{
		head->ordiniTavolo = InsInFondoPiatto(head->ordiniTavolo, piatto->costo, piatto->tavolo, piatto->nome);
		return head;
	}
	else{
		ListaT temp = (ListaT)malloc(sizeof(Tavolo));
		temp->tavolo = piatto->tavolo;
		temp->ordiniTavolo = NULL;
		temp->ordiniTavolo = InsInFondoPiatto(temp->ordiniTavolo, piatto->costo, piatto->tavolo, piatto->nome);
		temp->next = head;
		return temp;
	}
}

void organizzaPerTavoli1(ListaT *tavolo, ListaP head)
{
	if(head == NULL)
		return;
	*tavolo = InsTavolo(*tavolo, head);
	organizzaPerTavoli1(tavolo, head->next);
}

ListaP costruisci()
{
ListaP lista = NULL;
lista = InsInFondoPiatto(lista, 10.5, 1, "Karelian Pie"); lista = InsInFondoPiatto(lista, 8.0, 1, "Makkara");lista = InsInFondoPiatto(lista, 12.0, 1, "Musta Makkara");lista = InsInFondoPiatto(lista, 20, 2, "Baltic Herrings");lista = InsInFondoPiatto(lista, 20, 2, "Pasta all'Amatriciana");lista = InsInFondoPiatto(lista, 20, 1, "Herrings");lista = InsInFondoPiatto(lista, 20, 4, "Sgombro al Limone");lista = InsInFondoPiatto(lista, 20, 4, "Tiramisu'");return lista;
}


ListaP InsInFondoPiatto(ListaP lista, float costo, int tavolo, Tipo nome)
{
    ListaP punt;
        if(lista==NULL) { punt = (ListaP)malloc( sizeof(Piatto) );
                     punt->next = NULL; punt->costo = costo; punt->tavolo = tavolo; strcpy(punt->nome,nome);return punt;
    }else{lista->next = InsInFondoPiatto(lista->next,costo, tavolo, nome); return lista;}
}


void VisualizzaListaP(ListaP lista)
{
  if (lista==NULL) printf(" ---| \n");
    else{printf("\n nome:%s, tav:%d (%.2f) ---> ", lista->nome, lista->tavolo, lista->costo);
     VisualizzaListaP(lista->next);}
}

