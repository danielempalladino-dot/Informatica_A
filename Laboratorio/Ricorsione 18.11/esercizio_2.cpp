/*Si scriva una funzione RICORSIVA che, dato un array di interi, riempia un nuovo array con tutti e soli gli elementi pari dell'array in input e stampi il risultato. Ad esempio, se in input viene dato l'array

[8, 3, 4, 1, 1, 3, 6]

il programma stamperà

[8, 4, 6]

ATTENZIONE! Non basta stampare l'output, alla fine deve esistere un array contenente tutti e soli i valori pari dell'array di input.*/
#include <stdlib.h>
#include <stdio.h>
#define N 5

void estraipari(int v[], int lv, int p[], int *k);
int main()
{
	int v[N]={1,2,3,4,5};
	int pari[N];
	int k=0, i=0;
	estraipari(v,N-1,pari,&k);
	for(i=0; i<k; i++)
		printf("%d," , pari[i]);
}

void estraipari(int v[], int lv, int p[], int *k)
{
	if (lv<0)
		return;
	estraipari(v,lv-1,p, k);
	if (v[lv]%2==0)
	{
		p[*k]=v[lv];
		(*k)++;
	}
}
