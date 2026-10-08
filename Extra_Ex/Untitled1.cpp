#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 50
#define DIM 10
typedef struct
{
	char nome[N]; //nome ella lingua parlata
	char vitalita [N]; //es. viva, in pericolo, estinta
} lingua_t;

typedef struct{
	char nome[N]; 
	int pop; //numero abitanti
	lingua_t lingua; //lingua parlata
} popolo_t;

typedef struct{
	popolo_t popolo [DIM]; //vettore di popoli
	int n; //numero effettivo di popoli presenti
} popolazione_t;

void analizzaPopoli (popolazione_t p, char popmax[], char popmed[]) //chimao le due stringhe id appoggio cosi perche osno gia puntatori di loro natura, non serve deferenziarle
{
	int i = 0, somma = 0, int max =0;
	for(i=0;i<p.n; i++)
	{
		somma = somma + p.popolo[i].pop;
	}
	float media = (float)media/(p.n);
	strcpy(popmax, p.popolo[0].pop);
	float differenza = fabs(p.popolo[0]-media);
	strcpy(popmed, p.popolo[0].pop);
	for(i=1;i<p.n;i++)
	{
		if(p.popolo[i].pop > max)
		{
			max = p.popolo.pop;
			strcpy(popmax,p.popolo[i].nome)
		}
		if (fabs(p.popolo[i].pop-media)<differenza)
		{
			differenza = fabs(p.popolo[i].pop-media);
			strcpy(popmed, p.popolo[i].nome);
		}
	}
}
int filtrapopoli(popolazione_t *p, char vitalita[])
{
	int i, j = 0;
	for (i=0; i < p->n; i++)
	{
		if (strcmp(p->popolo[i].lingua.vitalita) == 0)
		{
			p->popolo[j]= p->popolo[i];
			j++;
		}
	}
	p->n = j;
	return j;
}
