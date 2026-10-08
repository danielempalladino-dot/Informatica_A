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
int confronta(char v1[], char v2[]);
Lista elimina(Lista);
//
// TODO: PROTOTIPI DELLE FUNZIONI RICHIESTE
//




int main(){
	Lista lis;
	lis=costruisci();
	VisualizzaListaStringhe(lis);
	lis = elimina(lis);


	//TODO: invocazione funzione
	
	
    printf("Lista dopo pulizia\n");
	VisualizzaListaStringhe(lis);


	return 0;
}


//
// TODO: SVILUPPARE QUI LE FUNZIONI RICHIESTE
//
int confronta(char v1[], char v2[])
{
	int i = 0;
	while(v2[i+2]!='\0')
	{
		i++;
	}
	if(v1[0] == v2[i] && v1[1]==v2[i+1])
		return 1;
	return 0;
}

Lista elimina(Lista l)
{
    if (l == NULL || l->prox == NULL)
        return l;

    Lista head = l;
    Lista prev = NULL;
    Lista p1 = l;
    Lista p2 = l->prox;

    while (p2 != NULL)
    {
        if (confronta(p1->info, p2->info) == 1)
        {
            Lista next = p2->prox;  // nodo dopo i due da eliminare

            if (prev == NULL)
            {
                // sto eliminando la testa
                head = next;
            }
            else
            {
                // collego il precedente al nodo successivo
                prev->prox = next;
            }

            // elimino i due nodi
            free(p1);
            free(p2);

            // riparto dal nodo successivo
            p1 = next;
            if (p1 != NULL)
                p2 = p1->prox;
            else
                p2 = NULL;
        }
        else
        {
            // avanza
            prev = p1;
            p1 = p2;
            p2 = p2->prox;
        }
    }

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

Lista InsInFondoStringa(Lista lista, char elem[])
{
    Lista nuovo = (Lista)malloc(sizeof(ElemLista));
    strcpy(nuovo->info, elem);
    nuovo->prox = NULL;

    if (lista == NULL)
        return nuovo;

    Lista p = lista;
    while (p->prox != NULL)
        p = p->prox;

    p->prox = nuovo;
    return lista;
}



void VisualizzaListaStringhe(Lista lista) {
    if (lista==NULL) printf(" ---| \n");
    else{printf(" %s ---> ", lista->info); VisualizzaListaStringhe( lista->prox );}
}

