#include <stdio.h>
typedef struct
{
	int x;
	int y;
}Punto;
typedef struct
{
	Punto a;
	Punto b;
	Punto c;
	Punto d;
}Rettangolo;

int LeggiNumero();
Punto leggiNumero();
Rettangolo Leggi();
int contenuto(Rettangolo r, Punto p);
void calcolo (Rettangolo r, int *p, int *q);

//condizione rettangolo -> lati paralleli agli assi: i duei punti devono avere stesa ascissa o ordinata)
//ora facciamo prima le funzioni
int LeggiNumero() //legge solo,serve un altra funzione che controlli ch ei punti inseriti formino un rettangolo.
{
	int a;
	scanf("%d", &a);
	return a;
}
Punto leggiPunto() //punto perche restituisce al main una variabile di tipo punto.
{
	Punto P;
	printf("Inserisci x: ");
	P.x = LeggiNumero ();
	printf("\nInserisci y:");
	P.y = LeggiNumero ();
	return P;
}
Rettangolo Leggi() //legge i punti e verifica che siano allineati e che compongano un rettangolo
{
	Rettangolo r;
	printf("\nInserisci il punto a: ");
	r.a = leggiPunto();
	do
	{
		printf("\nInserisci il punto b: ");
		r.b = leggiPunto();
	}
	while (r.a.y != r.b.y && r.a.x >= r.b.x); // abbiamo assunto che il punto b sia a destra del punto a e con la stessa altezza A __ B
	do
	{
		printf("\nInserisci il punto c: ");
		r.c = leggiPunto();
	}
	while (r.b.x != r.c.x && r.b.y <= r.c.y);
	r.d.x = r.a.x;
	r.d.y = r.c.y;
	return r;
}
int contenuto (Rettangolo r, Punto P) // verifica che il punto generico p sia contenuto all'interno dell'aria del rettangolo
{
	int flag = 0;
	if ((r.a.x < P.x && r.b.x > P.x)&&(r.a.y <P.y && r.d.y > P.y))
		flag = 1;
	return flag;
}
void calcolo (Rettangolo r, int *p, int *q)
{
	int a, b;
	a = r.b.x - r.a.x;
	if (a < 0)
		a= -a;
	b = r.c.y - r.b.y;
	if (b < 0)
		b = -b;
	*p = a * b;
	a = r.a.x - r.b.x;
	if (a < 0)
		a= -a;
	b = r.a.y - r.d.y;
	if (b < 0)
		b = -b;
	*q = 2*(a+b);
	//calcola perimetro
}
int main ()
{
	Rettangolo r;
	Punto p;
	int flag, area, perimetro; 
	p=leggiPunto();
	r=Leggi();
	flag= contenuto(r, p);
	if (flag)
		printf("Il punto si trova all'interno della figura!'");
	calcolo (r, &area, &perimetro);
	printf("\nL'area misura %d, e il perimetro misura %d", area, perimetro);
}
