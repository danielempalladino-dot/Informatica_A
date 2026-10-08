#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct n{
    char codice[100];
    int punteggio;
    struct n * next;
} nodo;
typedef nodo * Lista;






Lista InsInFondo(Lista lista,char c[],int p);
void VisualizzaLista(Lista lista );
Lista costruisci();
Lista caux(Lista lista,int i);
//
// TODO: PROTOTIPI DELLE FUNZIONI RICHIESTE
//
int aggregaPunti(Lista head, char nome[]);
Lista aggrega(Lista head);
Lista aggrega1(Lista head, Lista sol);
int is_present(Lista sol, Lista head);
Lista InsInFondo2(Lista sol, Lista head);

int main(){
	Lista lis,risultato;
	lis=costruisci();
	VisualizzaLista(lis);
	printf("\n\n");


	//TODO: invocazione funzione e visualizzazione risultato
	risultato = aggrega(lis);
	VisualizzaLista(risultato);
	return 0;
}


//
// TODO: SVILUPPARE QUI LE FUNZIONI RICHIESTE
//


int aggregaPunti(Lista head, char nome[])
{
	if(head == NULL)
		return NULL;
	int punti = 0;
	if(strcmp(head->codice, nome)==0)
		punti = head->punteggio;
	return punti + aggregaPunti(head->next, nome);		
}

int is_present(Lista sol, Lista head)
{
	if(sol == NULL || head == NULL)
		return 0;
	int flag = 0;
	if(strcmp(head->codice, sol->codice)==0)
		flag = 1;
	return flag + is_present(sol->next, head);
}
Lista InsInFondo2(Lista sol, Lista head)
{
	if(sol == NULL)
	{
		Lista pnew = (Lista)malloc(sizeof(nodo));
		strcpy(pnew->codice, head->codice);
		pnew->punteggio = aggregaPunti(head, head->codice);
		pnew->next = NULL;
		return pnew;
	}
	else { sol->next = InsInFondo2(sol->next, head);
	return sol;
	}
}

Lista aggrega(Lista head)
{
	if (head == NULL)
		return 0;
	Lista soluzione = NULL;
	soluzione = aggrega1(head, soluzione);
	return soluzione;
}

Lista aggrega1(Lista head, Lista sol)
{
	if(head == NULL)
		return NULL;
	if(is_present(sol, head) == 0)
		sol = InsInFondo2(sol, head);
	aggrega1(head->next, sol);
	return sol;
	
}

Lista costruisci(){ return caux(NULL,0);}
Lista caux(Lista lista,int i){
	int p[50]={57, 63, 70, 88, 91, 97, 57, 59, 66, 88, 94, 92, 77, 61, 68, 75, 85, 94, 68, 77, 63, 89, 85, 100, 57, 77, 59, 97, 68, 60, 87, 92, 94, 66, 61, 68, 75, 63, 89, 68, 75, 94, 57, 63, 75, 66, 92, 61, 77, 70};
	char c[50][20]={"c2", "c1", "c3", "c1", "c5", "c2", "c5", "c4", "c5", "c1", "c3", "c4", "c4", "c5", "c1", "c5", "c2", "c2", "c5", "c2", "c3", "c1", "c5", "c3", "c1", "c3", "c3", "c2", "c2", "c1", "c3", "c3", "c1", "c4", "c3", "c4", "c4", "c4", "c1", "c1", "c2", "c2", "c4", "c2", "c2", "c5", "c5", "c3", "c4", "c3"};
	if(i==50) return NULL;
	lista= (Lista)malloc( sizeof(nodo) );	lista->codice[0]=c[i][0]; lista->codice[1]=c[i][1]; lista->codice[2]=c[i][2]; lista->punteggio = p[i];    lista->next = caux(lista->next,i+1); return lista;
}


void VisualizzaLista(Lista lista ){
    if (lista==NULL) printf(" ---| \n");
    else{printf(" (%s,%i) ---> ", lista->codice, lista->punteggio); VisualizzaLista( lista->next );}
}

