#include <stdio.h>
#include <stdlib.h>
typedef struct El 
{
	int x;
	struct El *next;
} Nodo;
typedef Nodo *Lista;

Lista inserisciInTesta(Lista, int);
void stampaLista(Lista);
Lista inserisciInCoda(Lista, int);
int verificaPresenza(Lista, int);
Lista cerca(Lista, int);
int verificaPresenza1(Lista, int, Lista*); //variante con il puntatore ad una lista
Lista prendiCoda(Lista);
int lunghezzaListaRic(Lista l);
Lista cercaRic(Lista l, int x);
void distruggiLista(Lista);
//prima cosa da fare --> chiedersi se il puntatore alla lista è NULL
//fondamentale per le funzioni ricorsive

int main (){
	Lista l = NULL, p = NULL; 
	//IMPORTANTE --> inizializzare sempre la lista cosi da non avere errori
	int i;
	printf("%p", l);
	for(i=0;i<8;i++)
	{
		l=inserisciInTesta(l,i);
	}
	stampaLista(l);
	l = inserisciInCoda(l, 7);
	int x = 7, res;
	printf("\nLa lista contiene il numero %d: %d", x, verificaPresenza(l, x));
	printf("\nl'indirizzo della cella di %d nella lista e': %p", 0, cerca(l,0));
	res = verificaPresenza1(l, x, &p);
	printf("\nIl numero %d e' presente nella lista: %d, all'indirizzo %p", x, res, p);
	p = prendiCoda(l);
	printf("\nL'indirizzo della coda e': %p", p);
	return 0;
}

Lista inserisciInTesta(Lista l, int x){
	Lista pnew = (Lista)malloc(sizeof(Nodo));
	pnew->x = x;
	pnew->next = l;
	return pnew;
}
void stampaLista(Lista l){ 
	printf("\n|");
	while(l!=NULL)
	{
		printf(" %d ->", l->x);
		l=l->next;
	}
}
Lista inserisciInCoda(Lista l, int x){
	Lista pnew = (Lista)malloc(sizeof(Nodo));
	pnew->x = x;
	pnew->next = NULL;
	
	//caso base, la lista è NULL
	if(l==NULL)
		return pnew;
		
	//devo fermarmi al vagoncino prima della coda --> l->next == NULL
	//e soprattutto creareuna copia locale di temp
	Lista temp = l;
	
	while(l->next!=NULL)
		l = l->next; //ora l punta alla coda della lista
	l->next = pnew;
	return temp;
}
int verificaPresenza(Lista l, int x){
	while(l!=NULL)
	{
		if(l->x == x)
			return 1;
		l = l->next;
	}
	return 0;
}
Lista cerca(Lista l, int x){
	while(l!=NULL)
	{
		if(l->x == x)
			return l;
		l = l->next;
	}
	return NULL;
}
int verificaPresenza1(Lista l, int x, Lista *p){
	Lista temp = cerca(l,x);
	*p = temp;
	if (temp == NULL)
		return 0;
	return 1;
}
Lista prendiCoda(Lista l){
	if (l == NULL)
		return NULL;
	while (l->next != NULL)
		l = l->next;
	return l;
}
int lunghezzaListaRic(Lista l){
	//caso base
	if(l == NULL)
		return 0;
		//passo induttivo
	return 1 + lunghezzalistaRic(l->next);
}
Lista cercaRic(Lista l, int x){
	//caso base 1 
	if(l==NULL)
		return NULL;
	//caso base 2
	if (l->x == x)
		return l;
	cercaRic(l->next, x);
}
void distruggiLista(Lista l)
{
	Lista temp;
	while(l!=NULL)
	{
		ptemp = l->next;
		free(l);
		l = temp;
	}
}
void distruggiLista2(Lista *l)
{
	Lista temp;
	while(*l!=NULL)
	{
		ptemp = *l->next;
		free(*l);
		*l = temp;
	}
	*l = NULL;
}
Lista insCodaRic(Lista l, int x)
{
	//caso base
	if(l == NULL)
		return inserisciInTesta(Lista l, int x);
	//passo ricorsivo
	l->next = insCodaRic(l->next, x);
	return l;
		
}

Lista insOrd(Lista l, int x)
{
	//caso base
	if (l==NULL)
		return inserisciInCoda(l,x);
	//secondo caso base --> non utilizzo la proprità della ricorsione se il mio numero deve essere inserito nella prima casella
	if (l->x>x)
		return inserisciInCoda(l,x);
	//terzo caso base, se il carattere coincide ed è gia presenze--> è gia ordinato
	if(l->x == x)
		return l;
	l->next = insOrd(l->next, x);
	return l;
}
//passata per copia, anche se è un puntatore è passato come copia
//per le funzioni ricorsive infatti uso *lista == **nodo --> DOPPIO PUNTATORE
