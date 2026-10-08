#include<stdio.h>
#include <stdlib.h>
typedef struct El{
	int x;
 	struct El *next;
}Nodo;
typedef Nodo *Lista;

Lista inserisciInTesta(Lista l, int x);
void stampaLista(Lista l);
void stampaListaRic(Lista l);
void stampaListaRic1(Lista l);
void stampaListaRev(Lista l);
void stampaListaRev1(Lista l);
void distruggiListaRic(Lista l);
Lista distruggiNodo(Lista l, int x);
int main()
{
	Lista l = NULL;
	int i=0;
	for(i=0; i<10; i++)
	{
		l = inserisciInTesta(l, i);
	}
	stampaLista(l);
	stampaListaRic(l);
	stampaListaRev(l);
	distruggiListaRic(l); l = NULL;
	stampaListaRev(l);
}

Lista inserisciInTesta(Lista l, int x)
{
		Lista pnew = (Lista)malloc(sizeof(Nodo));
		pnew->x = x;
		pnew->next=l;
		return pnew;
}
void stampaLista(Lista l)
{
	printf("\n|-- ");
	while(l!=NULL)
	{
		printf(" %d ->", l->x);
		l = l->next;
	}
}
void stampaListaRic(Lista l)
{
	printf("\n|-- ");
	stampaListaRic1(l);
}
void stampaListaRic1(Lista l)
{
	if(l==NULL) //CASO BASE, la lista è vuota
	{
		printf("|");
		return;
	}
	//istruzione
	printf("%d -> ", l->x);
	//passo induttivo, stampo la lista dopo-
	stampaListaRic1(l->next);
}
void stampaListaRev(Lista l)
{
	printf("\n");
	stampaListaRev1(l);
	printf("--|");
	
}
void stampaListaRev1(Lista l)
{
	//caso base
	if(l==NULL)
	{
		printf("| ");
		return;
	}
	stampaListaRev1(l->next);
	printf("<- %d ", l->x);
}

void distruggiListaRic(Lista l)
{
	if(l==NULL)
		return;
	distruggiListaRic(l->next);
	free(l);
}

Lista distruggiNodo(Lista l, int x)
{
	Lista temp;
	//caso base
	if(l == NULL)
		return l;
	//secondo caso base --> la testa contiene l'elemento da eliminare
	if(l->x == x)
	{
		temp = l->next;
		free(l);
		return temp;
	}
	//passo ricorsivo, associo all'indirizzo di return di distruggiNodo
	//l'indirizzo del prossimo valore della lista, cosi da riuscire a mantenerla continua
	//senza creare garbage o rompere i puntatori
	l->next = distruggiNodo(l->next, x);
	return l;
}
