#include <stdio.h>
#include <stdlib.h>


// Definizione della struttura Nodo
typedef struct N {
    int valore;
    struct N * left;
    struct N * right;
} Nodo;
typedef Nodo * Albero;

typedef struct el{
	int x;
	struct el *next;
}Node;

typedef Node* Lista;

Albero nuovoNodo(int valore);
void stampaAlbero(Albero t);
void print(Albero t);
int contaFoglie (Albero t);
void somma(Albero t, Lista *head, int *sum);
void f(Albero t);
void VisualizzaLista(Lista lis);
void liberaSomme(Lista head);
int main() {
    // Creazione dell'albero
    Albero radice = nuovoNodo(3);
    radice->left = nuovoNodo(4);
    radice->right = nuovoNodo(9);
    radice->left->left = nuovoNodo(2);
    radice->left->right = nuovoNodo(7);
    radice->right->left = nuovoNodo(8);
    radice->left->left->left = nuovoNodo(1);
    radice->left->left->right = nuovoNodo(3);


    // Stampa dell'albero
    printf("Stampa dell'albero in ordine antecedente (radice, left, right):\n");
    stampaAlbero(radice);
    f(radice);


    return 0;
}

void f(Albero t)
{
	if(t==NULL)
		return;
	Lista somme = NULL;
	int val = 0;
	somma(t, &somme, &val);
	VisualizzaLista(somme);
	liberaSomme(somme);
}

void liberaSomme(Lista head)
{
	if (head==NULL)
		return;
	liberaSomme(head->next);
	free(head);
	head = NULL;
}

void VisualizzaLista(Lista lis) {
    if (lis == NULL)
        printf(" ---| \n");
    else {
        printf(" %d ---> ", lis->x);
        VisualizzaLista(lis->next);
    }
}

Lista InsInFondo(Lista lis, int elem) {
    Lista punt;
    if (lis == NULL) {
        punt = (Lista)malloc(sizeof(Node));
        punt->next = NULL;
        punt->x = elem;
        return punt;
    } else {
        lis->next = InsInFondo(lis->next, elem);
        return lis;
    }
}

int contaFoglie (Albero t)
{
	if(t==NULL)
		return 0;
	int cont = 0;
	if(t->left == NULL && t->right == NULL)
		cont++;
	return cont + contaFoglie(t->left) + contaFoglie(t->right);
}

void somma(Albero t, Lista *head, int *sum)
{
	if(t == NULL)
		return;
	(*sum) = (*sum) + t->valore;
	if(t->left == NULL && t->right == NULL)
	{
		*head = InsInFondo(*head, *sum);
	}
	somma(t->left, head, sum);
	somma(t->right, head, sum);
	(*sum) = (*sum) - t->valore;
}

// Funzione per creare un nuovo nodo
Albero nuovoNodo(int valore) {
    Albero nodo = (Albero) malloc(sizeof(Nodo));
    nodo->valore = valore;
    nodo->left = NULL;
    nodo->right = NULL;
    return nodo;
}


// Funzione per stampare l'albero
void stampaAlbero(Albero t) { print(t); printf("\n");}
void print(Albero t) {
    if (t == NULL)return;
    else {
        printf(" (");
        print(t->left);
        printf(" %d ", t->valore);
        print(t->right);
        printf(") ");
    }
}

