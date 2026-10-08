#include <stdlib.h>
#include <stdio.h>


typedef struct nodo {
    int valore;
    struct nodo *next;
} nodo;


typedef nodo *lista;


lista InsInFondo(lista lis, int elem);
void VisualizzaLista(lista lis);
lista costruisci();
lista aggiungi(lista head);

int main() {
    lista lis = costruisci();
    VisualizzaLista(lis);
	
    // TODO: invocazione funzione
    // TODO: visualizzazione lista output
    lis = aggiungi(lis);
    VisualizzaLista(lis);

    return 0;
}

lista aggiungi(lista head)
{
	if(head == NULL || head->next == NULL)
		return head;
	lista prox = head->next;
	if(head->valore != prox->valore-1)
	{
		lista pnew = (lista)malloc(sizeof(nodo));
		pnew->valore = head->valore+1;
		pnew->next = prox;
		head->next = aggiungi(pnew);
	}
	else head->next = aggiungi(head->next);
	return head;
}

lista InsInFondo(lista lis, int elem) {
    lista punt;
    if (lis == NULL) {
        punt = (lista)malloc(sizeof(nodo));
        punt->next = NULL;
        punt->valore = elem;
        return punt;
    } else {
        lis->next = InsInFondo(lis->next, elem);
        return lis;
    }
}


void VisualizzaLista(lista lis) {
    if (lis == NULL)
        printf(" ---| \n");
    else {
        printf(" %d ---> ", lis->valore);
        VisualizzaLista(lis->next);
    }
}


lista costruisci() {
    // 1 -> 2 -> 5 -> 7 -> 8
    lista lis = NULL;
    lis = InsInFondo(lis, 1);
    lis = InsInFondo(lis, 2);
    lis = InsInFondo(lis, 5);
    lis = InsInFondo(lis, 7);
    lis = InsInFondo(lis, 8);


    return lis;
}

