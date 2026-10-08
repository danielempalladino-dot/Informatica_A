#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 100
typedef char Stringa[LEN];

typedef struct NodeStruct{
	Stringa data;
	struct NodeStruct *next;
}Node;

typedef Node *pNode;

//funzione che controlla se la stringa inizia con quel prefisso
int controlloPrefisso(Stringa, Stringa);
//funzione che fa scorrere la lista e confronta con il prefisso
pNode copiaPrefisso(pNode head1, pNode head2, Stringa prefisso);
//in input: La lista di stringhe, la seconda lista dove va a copiare le cose e la stringa del prefisso

int main()
{
	//popola la lista e invoca la funzione
}

int controlloPrefisso(Stringa s, Stringa prefisso)
{
	//caso 1: la stringa vuota o lunghezza del prefisso più corta
	int len_prefisso = strlen(prefisso);
	if(strlen(s)<len_prefisso)
		return 0;
	for(int i=0; i<len_prefisso; i++) //< perche non vogliamo considerare il carattere terminatore
		if(s[i]!=prefisso[i]) //sono diversi
			return 0;
	//se non sono diversi allora sono uguali --> ritorno 1
	return 1;
}
pNode copiaPrefisso(pNode head1, pNode head2, Stringa prefisso)
{
	if(head1 == NULL)
	{
		printf("ERRORE");
		return head2;
	}
	pNode curr = head1;
	while(curr != NULL)
	{
		if(controllaPrefisso(curr->data, prefisso))//se controlla prefisso è vero --> ritorna 1
			head2=inserisciInCoda(head, curr->data); //copio in coda il mio numero
		curr = curr->next; //scorro la lista
	}
	return head2;
}
