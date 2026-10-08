#include<stdio.h>
#include<stdlib.h>


typedef struct EL{
        int info;
        struct EL * prox;
} ElemLista;
typedef ElemLista * ListaDiElem;


int ListaVuota( ListaDiElem lista );
ListaDiElem InsInTesta( ListaDiElem lista, int elem );
ListaDiElem crea1();
ListaDiElem crea2();
void VisualizzaLista( ListaDiElem lista );
ListaDiElem cercaDiv3(ListaDiElem lista1);
ListaDiElem aggDiv3(ListaDiElem lista1, ListaDiElem l);
ListaDiElem Finale(ListaDiElem, ListaDiElem);

int main() {
    ListaDiElem lista=NULL,lista1=NULL,lista2=NULL;     
    lista1=crea1();
    lista2=crea2();
    VisualizzaLista(lista1);
    printf("\n\n");
    VisualizzaLista(lista2);
    printf("\n\n");
    
    //inserire qui il codice
    lista = Finale(lista1, lista2);
    VisualizzaLista(lista);
    printf("\n\n");
    
    return 0;
}


void VisualizzaLista( ListaDiElem lista ) {
    if ( ListaVuota(lista) )
		printf(" ---| \n");
    else {
        printf(" %d ---> ",lista->info); 
        VisualizzaLista(lista->prox);
    }
}


ListaDiElem InsInTesta( ListaDiElem lista, int elem ) {
	ListaDiElem punt;
	punt = (ListaDiElem) malloc(sizeof(ElemLista));
	punt->info = elem;
	punt->prox = lista;		
	return  punt;
}


int ListaVuota( ListaDiElem lista ) {
    return lista == NULL;
}


ListaDiElem crea1() {
    ListaDiElem lis=NULL;            
    lis=InsInTesta( lis, 2 );
    lis=InsInTesta( lis, 12 );
    lis=InsInTesta( lis, 1 );
    lis=InsInTesta( lis, 4 );
    lis=InsInTesta( lis, 8 );
    lis=InsInTesta( lis, 34 );
    lis=InsInTesta( lis, 78 );
    lis=InsInTesta( lis, 26 );
    lis=InsInTesta( lis, 33 );
    lis=InsInTesta( lis, 11 );
    lis=InsInTesta( lis, 67 );
    lis=InsInTesta( lis, 83 );
    lis=InsInTesta( lis, 92 );
    return lis; 
}


ListaDiElem crea2() {
    ListaDiElem lis=NULL;            
    lis=InsInTesta( lis, 2 );
    lis=InsInTesta( lis, 10 );
    lis=InsInTesta( lis, 15 );
    lis=InsInTesta( lis, 48 );
    lis=InsInTesta( lis, 82 );
    lis=InsInTesta( lis, 11 );
    lis=InsInTesta( lis, 92 );
    lis=InsInTesta( lis, 22 );
    lis=InsInTesta( lis, 36 );
    lis=InsInTesta( lis, 19 );
    lis=InsInTesta( lis, 69 );
    return lis;
}

ListaDiElem cercaDiv3 (ListaDiElem lista1)
{	
	if(lista1 == NULL)
		return NULL;
	if(lista1->info % 3 == 0)
		return lista1;
	cercaDiv3(lista1->prox);
}

ListaDiElem aggDiv3(ListaDiElem lista1, ListaDiElem l)
{
	while (lista1!=NULL)
	{
		lista1 = cercaDiv3(lista1);
		l=InsInTesta(l, lista1->info);
		lista1 = cercaDiv3(lista1->prox);
	}
	return l;
	
}

ListaDiElem Finale(ListaDiElem lista1, ListaDiElem lista2)
{
	ListaDiElem p = NULL, l = NULL;
	l = aggDiv3(lista1, l);
	l = aggDiv3(lista2, l);
	p = l;
	while (l->prox != NULL)
		{
			while(p->prox != NULL)
			{
			}
			
		}
	return l;
}


