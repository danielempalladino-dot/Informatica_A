/*Si scriva una funzione RICORSIVA che stampi a video gli elementi di un array di interi (passato in input) in ordine inverso. Ad esempio, se in input viene dato l'array

[1, 6, 4, 5, 8]

il programma stamperà

[8, 5, 4, 6, 1]*/
#include <stdio.h>
#define N 5
void stampaInversa(int v[], int l);
void popolaVettore(int v[], int *l);
int main()
{
	int l, v[N];
	popolaVettore(v, &l);
	stampaInversa(v, l-1);
}

void popolaVettore(int v[], int *l)
{
	int i;
	*l=0;
	for(i=0; i<N; i++)
	{
		printf("Inserisci valore v[%d]: ", i);
		scanf(" %d", &v[i]);
	}
	*l = i;
}

void stampaInversa(int v[], int l)
{
	if (l == 0)
		printf("%d", v[0]);
	else
	{
		printf("%d, ", v[l]);
		stampaInversa(v, l-1);
	}
}
