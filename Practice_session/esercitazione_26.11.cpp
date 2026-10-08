#include <stdio.h>
#include <stdlib.h>
typedef struct NodeStruct{
	int data;
	struct NodeStruct *next;
}Node;
typedef Node *pNode;

pNode inserisciCoda(pNode head, int new_data);
int trovaMax(pNode, int*);
pNode trovaMaxRic(pNode);
pNode insPos (pNode head, int n_data, int pos);

int main()
{
	int err = 0;
	pNode head = NULL;
	head = inserisciCoda(head, 10);
	head = inserisciCoda(head, 5);
	int max = trovaMax (head, &err);
	if(!err)
	{
		printf("il massimo e': %d", max);
	}
	else
		printf("ERRORE!");
		
	head = insPos(head, 69, 2);
	max=trovaMax(head, &err);
	printf("sium %d", max);
	
	
}

pNode inserisciCoda(pNode head, int new_data)
{
	pNode news = (pNode) malloc(sizeof(Node));
	if(news == NULL)
	{
		//caso in cuila malloc non andasse a buon fine poichè la memeoria del computer è piena
		printf("ERRORE");
		return head;
	}
	news -> data = new_data;
	news -> next = NULL;
	if (head == NULL)
	//caso in cui la nostra lista è vuota, quindi la testa punta a NULL
		return news;
	pNode corrente = head;
	while(corrente->next != NULL)
		//scorro la lista fino alla cella prima di NULL
		corrente = corrente->next;
	corrente->next = news;
	return head; //faccio ritaornare sempre la testa della mia lista.
}
int trovaMax(pNode head, int *err)
{
	*err=0;
	if (head == NULL)
	{
		*err = 1;
		return 0;
	}
	pNode curr = head->next;
	int max = head->data;
	while (curr != NULL)
	{
		if(max<curr->data)
			max=curr->data;
		curr = curr->next;
	}
	return max;
}
pNode trovaMaxRic(pNode head)
{
	if(head == NULL);
	//caso base --> lista vuota
		return NULL;
	if(head->next == NULL)
	//caso base semplice --> la lista è composta da un solo elemento, il massimo è quello
		return head;
	pNode maxRes = trovaMaxRic(head->next);//al primo ciclo, maxRes == all'ultimo valore
	//con questo, scorro la mia lista finche non arrivo all'ultima casella, quando l'ultima casella ritorna, avro maxres = al valore dell'ultima cella, e ritornero il valore maggiore, e cosi via.
	//ora faccio il caso del penultimo nodo: controllo se il penultimo nodo è maggiore dell'ultimo nodo
	if (maxRes->data>head->data)
		return maxRes; //caso in cui l'ultimo è maggiore
	else return head; //caso in cui la cella di memoria puntata dalla funzione è maggiore
}

pNode insPos (pNode head, int n_data, int index)
{
	if(index<0)
	{
		//ERRORE --> posizione negativa
		printf("ERRORE!!!");
		return head;
	}
	if(head == NULL)
	{
	//caso in cui la lista sia vuota
		if (index == 0)
			return inserisciTesta(head, n_data);
		else 
		{
			printf("ERRORE!!!");
			return head;
		}	
	}
	if(index == 0)
		return inserisciTesta(head, n_data);
	pNode news = (pNode)malloc(sizeof(Node));
	//alloc ko
	if(news == NULL)
	{
		printf("ERRORE!!!");
		return head;
	}
	news->data = n_data;
	news->next = NULL;
	int pos = 0;
	pNode curr = head, prec = NULL;
	while(curr != NULL, pos<index)
	{
		//associo precedente e poi aumento il valore di curr
		prec = curr;
		curr = curr->next;
		pos++;
	}
	if(pos!=index)
	{
		printf("ERRORE!");
		free(news);
		return head;
	}
	else 
	{
		prec->next=news;
		news->next=curr;
		return head;
	}
}
	


