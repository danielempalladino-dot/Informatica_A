#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
	int x;
	int y;
	char p;
}punto;

typedef struct El{
	punto p;
	struct El *next;
}Nodo;
typedef Nodo *Lista;

Lista InsInFondo(Lista lista, punto x) 
{
	Lista punt;
	if( lista==NULL ) 
	{
		punt = (Lista)malloc(sizeof(Nodo));
		punt ->next = NULL; 
		punt ->p = x; 
		return punt;
	}
	else 
	{ 
		lista->next = InsInFondo( lista ->next, x);
		return lista; 
	}
}

Lista inserisciVertici();
float perimetro1(Lista);
float perimetro(Lista);
int main()
{
	float peri = 0;
	Lista poligono = NULL;
	poligono = inserisciVertici();
	peri = perimetro(poligono);
	printf("\nPerimetro: %.2f", peri);
	
	
}
Lista inserisciVertici()
{
	Lista poligono = NULL;
	int v=0;
	printf("quanti vertici ha il poligono?\t");
	scanf("%d", &v);
	for (int i=0; i<v;i++)
	{
		punto p;
		printf("\nPunto %d:\nInserisci x:\t", i);
		scanf("%d", &p.x);
		printf("Inserisci y:\t");
		scanf("%d", &p.y);
		fflush(stdin);
		printf("Inserisci Nome punto:\t");
		scanf("%c", &p.p);
		poligono = InsInFondo(poligono, p);
	}
	return poligono;
}

float perimetro1(Lista head)
{
	float peri = 0;
	//caso base errore
	if (head == NULL)
	{
		printf("LISTA VUOTA!");
		return 0;
	}
	//caso base -> sono all'ultimo punto del mio poligono
	if (head->next == NULL)
		return 0;
	//calcoo il mio lato
	peri = perimetro1(head->next);
	if(head->next->next==NULL)
		return peri;
	peri = peri + sqrt(pow(head->p.x - head->next->p.x, 2) + pow(head->p.y - head->next->p.y, 2));
	printf("%f", peri);
	return peri;
}

float perimetro (Lista head)
{
	//funzione di wrapping per calcolare il mio ultimo lato 
	float perimetro = perimetro1(head);
	Lista curr = head;
	//arrivo alla coda con il mio puntatore curr
	while (curr->next != NULL)
		curr = curr->next;
	//distanza testa coda
	perimetro = perimetro + (sqrt(pow(curr->p.x - head->p.x, 2)+pow(curr->p.y - head->p.y, 2)));
	return perimetro;
}
