#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NodeStruct{
	int data;
	struct NodeStruct *next;
}Node;

typedef Node *pNode;

pNode EliminaPRic(pNode head, int pos)
{
	if(pos<0)
		return head;
	if(head == NULL)
	{
		printf("LISTA VUOTA");
		return head;
	}
	//idea: continuo a scorrere la mia funzione ricorsivamente decrementando la posizione del nodo che voglio eliminare
	//quando pos=zero sara il nodo che voglio eliminare
	if (pos==0)
	{
		pNode temp = head;
		head = head->next
		free(temp);
		return head;
		//se è il nodo che voglio eliminare: creo un temporaneo, faccio diventare head il nodo successivo e libero la memoria.
		//facendo ritornare head, la chiamata ricorsiva associa al head->next del nodo prima di quello che volevo cancellare, il nodo dopo
		//mantenendo cosi la continuita. se invece non è il caso della funxione faccio ritornare semplicemente head cosi da mantenere la continuita della funzione
	}
	//chiamata ricorsiva: DEVO MANTENERE LA CONTINUITà DEI PUNTATORI
	head->next = EliminaPRic(head->next, pos--);
	return head;
}

pNode EliminaP(pNode head, int pos)
{
	if(pos<0)
		return head;
	if(head == NULL)
	{
		printf("LISTA VUOTA");
		return head;
	}
	//elimina la testa
	if(pos==0)
	{
		pNode temp = head;
		head = head->next
		free(temp);
		return head;
	}
	pNode curr=head, prec = NULL; //questa volta devo fare io il collegamento a mano
	int index=0;
	while(curr != NULL && index<pos)
	{
		prec = curr;
		curr = curr->next;
		pos++
	}
	if(curr == NULL)
	{
		printf("indice piu grande della lista");
		return head;
	}
	prec->next=curr->next;
	free(curr);
	return head;
}
