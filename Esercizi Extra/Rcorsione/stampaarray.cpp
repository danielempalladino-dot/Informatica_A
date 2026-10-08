#include <stdio.h>

void stampa(int v[], int l);

int main()
{
	int v[5]={1, 6, 4, 5, 8};
	stampa(v, 4);
}
void stampa(int v[], int l)
{
	if(l == 0)
	{
		printf("%d,", v[l]);
		return;
	}
	
	printf("%d, ", v[l]);
	stampa(v, l-1);
}
