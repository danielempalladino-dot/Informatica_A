#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct P {
    float x, y;
    struct P *next;
} Punto;


typedef Punto *Poligono;


typedef struct S {
    Poligono lisP;
    struct S *next;
} Pol;


typedef Pol *ListaPoligoni;


ListaPoligoni costruisci();
Poligono InsInFondoPunto(Poligono lista,float x,float y);
ListaPoligoni InsInFondoPoligono( ListaPoligoni lista,Poligono lis );
void VisualizzaPoligono(Poligono lista );
void VisualizzaListaPoligoni(ListaPoligoni lista );
float perimetro(Poligono head);
float wrapper(Poligono head);
void mediaListaPoligoni1 (ListaPoligoni head, float *p, float *n);
float mediaListaPoligoni(ListaPoligoni head);
ListaPoligoni rimuoviPoligoniCorti1(ListaPoligoni pol, float media);
ListaPoligoni rimuoviPoligoniCorti(ListaPoligoni head);
//AGGIUNGERE QUI PROTOTIPI




int main() {
    // Creazione di una lista di poligoni di esempio
    ListaPoligoni lista=costruisci();


    printf("Lista iniziale:\n");
    VisualizzaListaPoligoni(lista);


    //INSERIRE QUI INVOCAZIONI E STAMPA MEDIA PERIMETRI
    float media = mediaListaPoligoni(lista);
    printf("Media dei perimetri: %.2f\n\n", media);
    lista = rimuoviPoligoniCorti(lista);

    printf("Lista dopo l'eliminazione dei poligoni con perimetro sotto la media:\n");
    VisualizzaListaPoligoni(lista);
    

    return 0;
}


//AGGIUNGERE QUI LE FUNZIONI
ListaPoligoni rimuoviPoligoniCorti(ListaPoligoni head)
{
	if(head==NULL)
		return head;
	float media = mediaListaPoligoni(head);
	head = rimuoviPoligoniCorti1(head, media);
	return head;
	
}
ListaPoligoni rimuoviPoligoniCorti1(ListaPoligoni head, float media)
{
	if(head==NULL)
		return head;
	if(media>perimetro(head->lisP))
	{
		ListaPoligoni temp = head;
		head = head->next;
		free(temp);
		return rimuoviPoligoniCorti1(head, media);
	}
	head->next = rimuoviPoligoniCorti1(head->next, media);
	return head;
}

float mediaListaPoligoni(ListaPoligoni head)
{
	if(head == NULL)
		return 0;
	float peri = 0;
	float n = 0;
	mediaListaPoligoni1(head, &peri, &n);
	return peri/n;
}

void mediaListaPoligoni1(ListaPoligoni pol, float *p, float *n)
{
	if(pol == NULL)
		return;
	(*p) += perimetro(pol->lisP);
	(*n) ++;
	mediaListaPoligoni1(pol->next, p, n);
}


ListaPoligoni costruisci(){
	int M[5][10]={0,0,1,0,2,2,1,1,-1,-1,
	              1,6,9,1,5,5,1,9,0,8,
				  1,3,1,4,4,4,4,2,3,1,
				  1,3,2,4,0,2,0,0,-1,-1,
				  1,32,8,8,5,0,-1,-1,-1,-1};
	int i,k;ListaPoligoni ris=NULL; Poligono temp=NULL;
	for(i=0;i<5;i++){
		temp=NULL;for(k=0;k<10;k=k+2)if(M[i][k]!=-1)temp=InsInFondoPunto(temp,M[i][k],M[i][k+1]);
		ris=InsInFondoPoligono(ris,temp);}
	return ris;
}

float perimetro(Poligono head)
{
	if(head == NULL)
		return 0;
	Poligono prox = head;
	while (prox->next != NULL)
		prox = prox->next;
	float p = sqrt((pow(head->x - prox->x, 2))+(pow(head->y - prox->y, 2))) + wrapper(head);
	return p;
}

float wrapper(Poligono head)
{
	if(head == NULL || head->next == NULL)
		return 0;
	Poligono prox = head->next;
	float lato = sqrt((pow(head->x - prox->x, 2))+(pow(head->y - prox->y, 2)));
	return lato + wrapper(head->next);
}


Poligono InsInFondoPunto(Poligono lista,float x,float y) {
    Poligono punt;
    if(lista==NULL) { punt = (Poligono)malloc( sizeof(Punto) );
                     punt->next = NULL; punt->x = x; punt->y = y; return  punt;
    }else{lista->next = InsInFondoPunto(lista->next,x,y); return lista;}
}



ListaPoligoni InsInFondoPoligono( ListaPoligoni lista,Poligono lis ) {
   ListaPoligoni punt;
   if(lista==NULL) { punt = (ListaPoligoni)malloc( sizeof(Pol) );
                     punt->next=NULL; punt->lisP=lis; return  punt;
   }else{lista->next = InsInFondoPoligono(lista->next,lis); return lista;}
}


void VisualizzaPoligono(Poligono lista ){
    if (lista==NULL) printf(" ---| \n");
    else{printf(" (%.2f,%.2f) ---> ", lista->x, lista->y); VisualizzaPoligono( lista->next );}
}


void VisualizzaListaPoligoni(ListaPoligoni lista ) {
    if(lista==NULL) printf("\n");
    else{VisualizzaPoligono(lista->lisP); VisualizzaListaPoligoni(lista->next);}
}



