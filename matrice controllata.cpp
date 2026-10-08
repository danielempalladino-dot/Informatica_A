//insieme controllato di una matrice --> ogni volta che viene inserito un elemento, bisogna assicurarsi che non sia già presente
#include <stdio.h>
#define N 10
int main ()
{
	int r, c, i, j, flag, k, h, A [N][N]; //matrice di 100 interi
	do{
		scanf(" %d", &r)
	}
	while (r<0 || r>N);
	do{
		scanf(" %d", &c)
	}
	while (c<0 || c>N);
	//spazio reale minore di quello disponibile
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			do 
			{
				flag = 1;
				printf("Inserisci il valore della matrice (%d, %d)", i+1. j+1);
				scanf("%d";&A[i][j]);
				for (k=0; k<i && flag; k++)
					for(h=0; h<c && flag; h++)
						if(A[k][h]== A[i][j])
							flag = 0;
				for(k=0; k<j && flag; k++)
					if(A[i][k]==A[i][j])
						flag = 0;
			}
			while (flag == 0) //perche ==0 --> perche se la flag rimane invariata il ciclo non si manifesta
			//invece se se la flag diventa 0 richiede l'intero da inserire senza cambiare gli indici.
			
		}
	}
	
}
