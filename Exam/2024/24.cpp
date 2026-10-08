#include <stdio.h>

#define Q 100
#define N 8  // Numero di colonne (per matrici 8x8 o superiori)
typedef struct{
	int a;
	int b;
}numeri;
int AnalizzaMatrice(int M1[N][N], int k);
int AnalizzaMatrice2 (int M1[N][N], int k, numeri coppie[]);
int main() {
	int k, i, c;
	numeri coppie[Q];
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
    c = AnalizzaMatrice2(M1, k, coppie);
    printf("Numero di coppie per k = %d: %d", k, c);
    for(i=0;i<c;i++)
    	printf("\n(%d,%d)", coppie[i].a, coppie[i].b);
	k = 35;
    c = AnalizzaMatrice2(M1, k, coppie);
    printf("\n%d", c);
    for(i=0;i<c;i++)
    	printf("\n(%d,%d)", coppie[i].a, coppie[i].b);
	k = 200;
    c = AnalizzaMatrice2(M1, k, coppie);
    printf("\n%d", c);
    for(i=0;i<c;i++)
    	printf("\n(%d,%d)", coppie[i].a, coppie[i].b);
	k = 90;
    c = AnalizzaMatrice2(M1, k, coppie);
    printf("\n%d", c);
    for(i=0;i<c;i++)
    	printf("\n(%d,%d)", coppie[i].a, coppie[i].b);
	return 0;
}
int AnalizzaMatrice(int M[N][N], int k)
{
	int i=0, j=0, c=0;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			{
				if(j<N-1 && M[i][j]*M[i][j+1] == k)
					c++;
				if(i<N-1 && M[i][j]*M[i+1][j] == k)
					c++;
			}
	return c;
}
int AnalizzaMatrice2 (int M1[N][N], int k, numeri coppie[])
{
	int i=0, j=0, c=0;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			{
				if(j<N-1 && M1[i][j]*M1[i][j+1] == k)
				{
					coppie[c].a = M1[i][j];
					coppie[c].b = M1[i][j+1];
					c++;
				}
				if(i<N-1 && M1[i][j]*M1[i+1][j] == k)
				{
					coppie[c].a = M1[i][j];
					coppie[c].b = M1[i+1][j];
					c++;
				}
			}
	return c;
}
