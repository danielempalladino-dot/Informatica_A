#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct EL {
	char info[100];
	struct EL * prox;
} ElemLista;


typedef ElemLista * Lista;




Lista InsInFondoStringa(Lista lista,char elem[] );
void VisualizzaListaStringhe(Lista lista );
Lista costruisci();
//
// TODO: PROTOTIPI DELLE FUNZIONI RICHIESTE
//
int is_consecutive (char s1[], char s2[]);
Lista pulisci(Lista head);



int main(){
	Lista lis;
	lis=costruisci();
	VisualizzaListaStringhe(lis);


	//TODO: invocazione funzione
	
	
	lis = pulisci(lis);
    printf("Lista dopo pulizia\n");
	VisualizzaListaStringhe(lis);


	return 0;
}


//
// TODO: SVILUPPARE QUI LE FUNZIONI RICHIESTE
//

int is_consecutive (char s1[], char s2[])
{
	int i = 0;
	for(i=0; s1[i] != '\0'; i++);
	for(int j=0; j<2; j++)
	{
		if(s1[i-2+j] != s2[j])
			return 1;
	}
	return 0;
}

Lista pulisci(Lista head)
{
	if(head == NULL || head->prox == NULL)
		return head;
	Lista next = head->prox;
	if(is_consecutive(head->info, next->info) == 0)
	{
		free(head);
		head = next->prox;
		free(next);
		next = NULL;
		head = pulisci(head);
	}
	else head->prox = pulisci(head->prox);
	return head;
	
}


Lista costruisci(){
	Lista lis=NULL;
	lis=InsInFondoStringa(lis,"casa");lis=InsInFondoStringa(lis,"sale");lis=InsInFondoStringa(lis,"postino");
	lis=InsInFondoStringa(lis,"rame");lis=InsInFondoStringa(lis,"meta");lis=InsInFondoStringa(lis,"sasso");
	lis=InsInFondoStringa(lis,"osteria");lis=InsInFondoStringa(lis,"salvia");lis=InsInFondoStringa(lis,"notare");
	lis=InsInFondoStringa(lis,"renna");
	
	return lis;
}


Lista InsInFondoStringa(Lista lista,char elem[]) {
    Lista punt;
    if(lista==NULL) { punt = (Lista)malloc( sizeof(ElemLista) );
                     punt->prox = NULL; strcpy(punt->info,elem); return  punt;
    }else{lista->prox = InsInFondoStringa(lista->prox,elem); return lista;}
}


void VisualizzaListaStringhe(Lista lista) {
    if (lista==NULL) printf(" ---| \n");
    else{printf(" %s ---> ", lista->info); VisualizzaListaStringhe( lista->prox );}
}

