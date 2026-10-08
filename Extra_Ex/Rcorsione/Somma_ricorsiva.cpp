#include <stdio.h>

#define B 100
#define N 8  // Numero di colonne (per matrici 8x8 o superiori)

typedef struct {
	int x;
	int y;
}coordinate;

int analizzaMatrice(int M[][N], int k);
int confrontadx(int M[][N], int i, int j, int k);
int confrontasx(int M[][N], int i, int j, int k);
int analizzaMatrice2(coordinate v[], int M1[][N], int k);

int main() {
	coordinate v[B];
	int k, coppie = 0;
    int M1[N][N] = {
        {1, 2, 3, 4, 50, 6, 7, 8},
        {8, 7, 6, 50, 1, 3, 2, 1},
        {2, 3, 4, 5, 6, 7, 8, 9},
        {9, 8, 7, 6, 5, 4, 3, 2},
        {1, 3, 5, 7, 9, 7, 5, 3},
        {3, 0, 4, 1, 5, 9, 2, 6},
        {6, 2, 90, 5, 1, 4, 9, 3},
        {3, 5, 7, 9, 7, 5, 3, 1}
    };


    //casi di test: invocare la funzione e stampare le coppie per questi 4 casi
    k = 4;
    coppie = analizzaMatrice2(v, M1, k);
    printf("Numero di coppie: %d\n", coppie);
    for (int i=0; i<coppie; i++)
    {
    	printf("(%d,%d),", v[i].x, v[i].y);
	}
	printf("\n\n");
	k = 35;
    coppie = analizzaMatrice2(v, M1, k);
    printf("Numero di coppie: %d\n", coppie);
    for (int i=0; i<coppie; i++)
    {
    	printf("(%d,%d),", v[i].x, v[i].y);
	}
	printf("\n\n");
	k = 200;
    coppie = analizzaMatrice2(v, M1, k);
    printf("Numero di coppie: %d\n", coppie);
    for (int i=0; i<coppie; i++)
    {
    	printf("(%d,%d),", v[i].x, v[i].y);
	}
	printf("\n\n");
	k = 90;
    coppie = analizzaMatrice2(v, M1, k);
    printf("Numero di coppie: %d\n", coppie);
    for (int i=0; i<coppie; i++)
    {
    	printf("(%d,%d),", v[i].x, v[i].y);
	}
	printf("\n\n");
	return 0;
}

int confrontadx(int M1[][N], int i, int j, int k)
{
	if (M1[i][j]*M1[i][j+1]==k)
		return 1;
	return 0;
}

int confrontasx(int M1[][N], int i, int j, int k)
{
	if (M1[i][j]*M1[i+1][j]==k)
		return 1;
	return 0;
}

int analizzaMatrice(int M1[][N], int k)
{
	int i=0, j=0, count = 0;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
		{
			if(confrontadx(M1,i, j, k) == 1)
				count++;
			if (confrontasx(M1, i, j, k)==1)
				count ++;
		}
	return count;
}


int analizzaMatrice2(coordinate v[], int M1[][N], int k)
{
	int i=0, j=0, count = 0;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
		{
			if(confrontadx(M1,i, j, k) == 1)
			{
				coordinate p;
				p.x = M1[i][j];
				p.y= M1[i][j+1];
				v[count]=p;
				count++;
			}
			if (confrontasx(M1, i, j, k)==1)
			{
				coordinate p;
				p.x = M1[i][j];
				p.y= M1[i][j+1];
				v[count]=p;
				count ++;
			}
		}
	return count;
	
}
