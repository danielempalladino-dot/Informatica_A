#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void maxmin(int *m, int *M, int mat[]);
int main()
{
	int i, min, max, mat[N];
	srand(time(NULL));
	
	for(i=0;i<N;i++)
	{
		mat[i]= rand() % 100;
		printf("[%d]", mat[i]);
	}
	maxmin(&min, &max, mat);
	printf("\nMassimo: %d, Minimo: %d", max, min);
}

void maxmin(int *m, int *M, int mat[]) 
{
    int i;
    *M = mat[0];
    *m = mat[0];

    for (i = 1; i < N; i++) {
        if (mat[i] > *M)
            *M = mat[i];
        if (mat[i] < *m)
            *m = mat[i];
    }
}
