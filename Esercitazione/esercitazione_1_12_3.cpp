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

int simili(char *s1, cahr *s2)
{
	int l_1 = strlen(s1);
	int l_2 = strlen(s2);
	int lunghezza_min = 0;
	int distanza = 0;
	//caso base
	if(abs(l_1-l_2)>2)
		return 0;
	if(l_1<l_2)
		lunghezza_min = l_1;
	else 
		lunghezza_min = l_2;
	for(int i=0; i<lunghezza_min;i++)
	{
		if(s1[i]!=s2[i])
		{
			distanza++; //sono diversi
			if(distanza>2)
				return 0;
		}
	}
	if(distanza+(abs(l_1-l_2))>2)
		return 0;
	return 1;
}
int Stringhe(pNode head)
{
	if (head == NULL || head->next == NULL)
		return 1;
	pNode curr= head;
	while(curr->next != NULL) //finche il curr-> next non è nullo
	{
		//se non sono simili ritorno 0
		if(!simili(curr->data, curr->next->data))
			return 0;
		curr = curr->next;
	}
	return 1;
}



