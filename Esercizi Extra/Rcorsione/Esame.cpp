#include <stdio.h>
#include <stdlib.h>


typedef struct nodo {
    int dato;
    struct nodo *next;
} Nodo;

typedef Nodo* Lista;

typedef struct node{
	Lista L;
	struct node *next;
} Node;

typedef Node *sovraLista;

Lista costruisci();
Lista IIT(Lista l,int e);
Lista FL(int v[],int l);
void stampaLista(Lista lista);

sovraLista dividiListe (Lista lis, int s1, int s2);
Lista divisione (Lista l, int s1, int s2);


int main() {
	int s1=10,s2=20;
	Lista ris; 
    Lista Lis = costruisci();
    stampaLista(Lis);


	//INSERIRE QUI INVOCAZIONI DI FUNZIONE E STAMPE USANDO Lis, s1, s2 DEFINITI SOPRA


    return 0;
}
//INSERIRE QUI LE PROPRIE FUNZIONI

sovraLista dividiListe (Lista lis, int s1, int s2)
{
	int temp;
	if(s1>s2)
	{
		temp = s1;
		s1 = s2;
		s2= temp;
	}
	sovraLista sol = (sovraLista) malloc(sizeof(Node));
	sol = IITL(sol, Maggiori(lis, s2));
	sol = IITL(sol, Compresi(lis, s1, s2));
	sol = IITL (sol, Minori(lis, s1, s2));
	return sol;
}

Lista Minori (Lista head, int s1)
{
	if(head == NULL)
		return head;
	head->next = Minori(head->next, s1, s2);
	if(head->dato <s1)
		return head;
}

Lista Compresi(Lista head, int s1, int s2)
{
	if(head == NULL)
		return head;
	head->next = Compresi(head->next, s1, s2);
	if(head->dato >= s1 && head->dato <= s2)
		return head;
}

Lista Maggiori(Lista head, int s2)
{
	if(head == NULL)
		return head;
	head->next = Maggiori(head->next, s2);
	if(head->dato >s2)
		return head;
}

Lista costruisci(){int v[]={2,4,7,21,9,11,5,1,3,4,
                             12,6,23,11,8,12,7,11,4,100,
							 6,22,8,89,10,4,12,22,8,89,
							 10,4,12,16,65,1,-8,-6,4,2};return FL(v,40);}
Lista IIT(Lista l,int e){Lista p=(Lista)malloc(sizeof(Nodo));p->dato=e;p->next=l;return p;}
sovraLista IITL(sovraLista l,Lista head){sovraLista p=(SovraLista)malloc(sizeof(Node));p->L=head;p->next=l;return p;}
Lista FL(int v[],int l){Lista lis=NULL;for(l=l-1;l>=0;l--)lis=IIT(lis,v[l]);return lis;}


void stampaLista(Lista lis) {
    while(lis!=NULL) {
        printf("%d->",lis->dato);
        lis=lis->next;
    }
    printf("---|\n");
}

