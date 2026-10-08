#include <stdio.h>
#include <stdlib.h>


typedef struct nodo {
    int dato;
    struct nodo *next;
} Nodo;


typedef Nodo* Lista;


Lista costruisciA();
Lista costruisciB();
Lista costruisciC();
Lista costruisciD();
Lista costruisciE();
Lista costruisciF();
Lista IIT(Lista l,int e);
Lista FL(int v[],int l);
void stampaLista(Lista lista);

int verifica(Lista head1, Lista head2);
Lista mescolamento (Lista head1, Lista head2);
Lista mischia(Lista head1, Lista head2);

int main() {
	int uguali = -1;
	Lista ris; 
    Lista LA = costruisciA();
    Lista LB = costruisciB();
    Lista LC = costruisciC();
    Lista LD = costruisciD();
    Lista LE = costruisciE();
    Lista LF = costruisciF();
    printf("LA:");stampaLista(LA);
    printf("LB:");stampaLista(LB);
    printf("LC:");stampaLista(LC);
    printf("LD:");stampaLista(LD);
    printf("LE:");stampaLista(LE);
    printf("LF:");stampaLista(LF);


	//INSERIRE QUI INVOCAZIONI DI FUNZIONE E STAMPE
	uguali = verifica(LC, LE);
	printf("%d\n", uguali);
	ris = mischia(LA, LB);
	stampaLista(ris);


    return 0;
}
//INSERIRE QUI LE PROPRIE FUNZIONI

int verifica(Lista head1, Lista head2)
{
	int uguali = 0;
	if(head1 == NULL || head2 == NULL)
		return 0;
	
	if (head1->dato == head2->dato)
		uguali = 1;
	uguali = uguali + verifica(head1->next, head2->next);
	return uguali;
}

Lista mescolamento(Lista head1, Lista head2)
{
	if (head1==NULL || head2==NULL)
		return NULL;
	Lista pnew = NULL;
	if(head1->dato < head2->dato){
		pnew = IIT(pnew, head1->dato);
	}
	else {
		pnew = IIT(pnew, head2->dato);
	}
	pnew->next = mescolamento(head1->next, head2->next);
	return pnew;
}

Lista mischia(Lista head1, Lista head2)
{
	//primo caso
	if(verifica(head1, head2)>0)
		return NULL;
	//secondo caso
	else
	return mescolamento(head1, head2);
}

Lista costruisciA(){int v[]={2,4,7,21,9,11};return FL(v,6);}
Lista costruisciB(){int v[]={5,1,3,4,12,6};return FL(v,6);}
Lista costruisciC(){int v[]={23,11,8,12,7,11,4,100,6};return FL(v,9);}
Lista costruisciD(){int v[]={22,8,89,10,4,12};return FL(v,6);}
Lista costruisciE(){int v[]={23,8,4,12,7,11,4,100,6};return FL(v,9);}
Lista costruisciF(){int v[]={22,8,89,10,4,12};return FL(v,6);}
Lista IIT(Lista l,int e){Lista p=(Lista)malloc(sizeof(Nodo));p->dato=e;p->next=l;return p;}
Lista FL(int v[],int l){Lista lis=NULL;for(l=l-1;l>=0;l--)lis=IIT(lis,v[l]);return lis;}


void stampaLista(Lista lis) {
    while(lis!=NULL) {
        printf("%d->",lis->dato);
        lis=lis->next;
    }
    printf("---|\n");
}



