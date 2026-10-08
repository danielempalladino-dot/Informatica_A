#include <stdio.h>
#include <stdlib.h>

#define N 8

void analizzaMatrice(int A[N][N]) {
	int i, j, l, x, y, max_x, max_y, min_y;
	int temp;
	int max;
	
	printf("Analizzo matrice...\n");

    // Controlliamo tutti gli elementi della matrice
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			temp = A[i][j];
			max = 1;

            // Controlliamo la colonna
			for(l = 0; l < N && max; l++) {
				if(l != i) {
					max = max && (temp > A[l][j]);
				}
			}

            // Controlliamo la riga
			for(l = 0; l < N && max; l++) {
				if(l != j) {
					max = max && (temp > A[i][l]);
				}
			}

            // Definiamo i limiti di riga e colonna per la prima diagonale
			if(i > j) {
				x = i - j;
				y = 0;
				max_x = N;
				max_y = N - i + 1 + j;
			} else {
				x = 0;
				y = j - i;
				max_x = N - j + 1 + i;
				max_y = N;
			}

            // Controlliamo la prima diagonale
			while(x < max_x && y < max_y && max) {
				if(x != i) {
//					printf("Check %d > %d\n", temp, A[x][y]);
					max = max && (temp > A[x][y]);
				}
				x++;
				y++;
			}

            // Definiamo i limiti di riga e colonna per la seconda diagonale
			if(i + j >= N - 1) {
				x = i + j - N + 1;
				y = N - 1;
				max_x = N;
				min_y = x - 1;
			} else {
				x = 0;
				y = i + j;
				max_x = y + 1;
				min_y = -1;
			}

            // Controlliamo la secondo diagonale
			while(x < max_x && y > min_y && max) {
				if(x != i) {
//					printf("Check %d >> %d\n", temp, A[x][y]);
					max = max && (temp > A[x][y]);
				}
				x++;
				y--;
			}

            // Se max è ancora vero, allora l'elemento corrente soddisfa tutte le condizioni
			if(max) {
				printf("(%d, %d) %d\n", i, j, temp);
			}
		}
	}
	
	printf("\n");
}
	
int main() {    
    int M1[N][N]={ {  3,  5,  6,  23,  87, 23,  12,  1 },
                   { 11, 14, 76,  87,  92,  0,   0,  3 },
                   {  3,  9,  27, 81,   0, 12,  18, 24 },
                   {  1,  2,  0,   4,   7,  2,   1,  4 },
                   { 87, 34, 29,  98, 111, 76, 123, 99 },    
                   { 16, 14, 76,  89,  92, 16,   0,  3 }, 
                   { 3,  19, 11,  88,  15,  2,  18, 24 },
                   { 12, 29, 21,  88,  15,  2,  19, 25 } };

    int M2[N][N]={  {  3,   5,  6, 23, 87, 23,  12,  1 },
					{ 11,  14, 76, 87, 92,  0,   0,  3 }, 
                    {  3, 134, 27, 81,  0, 12,  18, 24 },
                    {  1,   2,  0,  4,  7,  2,   1,  4 },
					{ 87,   1, 29, 98, 11, 76, 123, 99 },    
					{ 16,  14, 76, 89, 92, 16,   0,  3 }, 
					{  3,  19, 11, 88, 15,  2,  18, 24 },
					{ 12,  29, 21, 88, 15,  2,  19, 25 }};

    int M3[N][N]={ 	{  3,   5,  6, 23,  87, 23,  12,  1 },
					{ 11,  14, 76, 87,  92,  0,   0,  3 }, 
                    {  3, 134, 27, 81,  15, 12,  18, 24 },
                    {  1,   2,  0,  2,   2,  2,   1,  0 },
					{ 87,   1, 29, 198, 111, 76, 123, 99 },    
					{ 16,  14, 76, 89,  92, 16,   0,  3 }, 
                    {  3,  19, 11, 88,  15,  2,  18, 24 },
					{ 12,  29, 21, 88,  15,  2,  19, 25 } };
    
    analizzaMatrice(M1);
    analizzaMatrice(M2);
    analizzaMatrice(M3);
    
    return 0;
}
