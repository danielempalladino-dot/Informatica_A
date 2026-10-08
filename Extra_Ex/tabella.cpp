#include <stdio.h>
#define N 8
#define Q 64
void AnalizzaMatrice (int M[N][N]);
int main ()
{   
    int M1[N][N]={ {  3,  5,  6,  23,  87, 23,  12,  1 },
                   { 11, 14, 76,  87,  92,  0,   0,  3 },
                   {  3,  9,  27, 81,   0, 12,  18, 24 },
                   {  1,  2,  0,   4,   7,  2,   1,  4 },
                   { 87, 34, 29,  98, 111, 76, 123, 99 },    
                   { 16, 14, 76,  89,  92, 16,   0,  3 }, 
                   { 3,  19, 11,  88,  15,  2,  18, 24 },
                   { 12, 29, 21,  88,  15,  2,  19, 25 } };
    AnalizzaMatrice(M1);
}

void AnalizzaMatrice (int M[N][N])
{
	int i=0, j=0, l=0, d=0, temp, max;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			temp = M[i][j];
			max = 1;
			for(l=0; l<N && max; l++)
				if(l!=i)
					max = max && (temp > M[l][j]);
			for(l=0; l<N; l++)
				if (l!=j)
					max = max && (temp > M[i][l]);
			for (d=1; d<N; d++)
				if (N>i+d && N>j+d)
				{
					max = max && (temp>M[i+d][j+d]);
				}
			for (d=1; d<N; d++)
				if (i-d>0 && N>j+d)
				{
					max = max && (temp>M[i-d][j+d]);
				}
			for (d=1; d<N; d++)
				if (N>i+d && j-d>0)
				{
					max = max && (temp>M[i+d][j-d]);
				}
			for (d=1; d<N; d++)
				if (i-d>0 && j-d>0)
				{
					max = max && (temp>M[i-d][j-d]);
				}
			if(max)
			{
				printf("(%d,%d) %d\n", i, j, temp);
			}
		}
}


