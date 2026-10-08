#include <stdio.h>
#include <stdlib.h>


/*
Sia data una lista contenente almeno due elementi i cui record sono definiti tramite la seguente struttura C:


typedef struct nodo{
    int valore;
    struct nodo* next;
} nodo;


Scrivere una funzione listapicchi che ricevuta in ingresso una lista ne restituisce una nuova costituita da tutti e soli i “picchi”,
cioè gli elementi della prima lista preceduti e seguiti da elementi aventi valore strettamente inferiore a quello dell’elemento stesso.


Il primo e l’ultimo elemento della lista non sono da considerarsi picchi.


Per esempio, se la lista in ingresso è
1 -> 5 -> 16 -> 11 -> 12 -> 4 -> 5 -> 5 -> 3 -> 1 -> 5
la lista restituita conterrà:
16 -> 12
*/


typedef struct nodo{
    int valore;
    struct nodo* next;
} nodo;
typedef nodo* lista;


lista InsInFondo(lista lis, int elem);
void VisualizzaLista(lista lis);
lista costruisci();
lista listapicchi(lista);



int main(){
    lista lis = costruisci(), picchi = NULL;
    VisualizzaLista(lis);
    picchi = listapicchi(lis);
    printf("\n");
    VisualizzaLista(picchi);


    // TODO: visualizzazione lista input
    // TODO: invocazione funzione
    // TODO: visualizzazione lista output


    return 0;
}

lista listapicchi(lista head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    lista pnew = NULL;
    lista prev = head;
    lista curr = head->next;
    lista next = curr->next;

    while (next != NULL) {
        if (prev->valore < curr->valore && curr->valore > next->valore) {
            pnew = InsInFondo(pnew, curr->valore);
        }
        prev = curr;
        curr = next;
        next = next->next;
    }

    return pnew;
}


lista InsInFondo(lista lis, int elem) {
    lista punt;
    if(lis == NULL){
        punt = (lista)malloc(sizeof(nodo));
        punt->next   = NULL;
        punt->valore = elem;
        return punt;
    }
    else {
        lis->next = InsInFondo(lis->next, elem);
        return lis;
    }
}




void VisualizzaLista( lista lis ) {
    if ( lis == NULL )
        printf(" ---| \n");
    else {
        printf(" %d\n ---> ", lis->valore);
        VisualizzaLista( lis->next );
    }
}


lista costruisci(){
    // 1 -> 5 -> 16 -> 11 -> 12 -> 4 -> 5 -> 5 -> 3 -> 1 -> 5
    lista lis = NULL;
    lis = InsInFondo(lis, 1);
    lis = InsInFondo(lis, 5);
    lis = InsInFondo(lis, 16);
    lis = InsInFondo(lis, 11);
    lis = InsInFondo(lis, 12);
    lis = InsInFondo(lis, 4);
    lis = InsInFondo(lis, 5);
    lis = InsInFondo(lis, 5);
    lis = InsInFondo(lis, 3);
    lis = InsInFondo(lis, 1);
    lis = InsInFondo(lis, 5);


    return lis;
}

