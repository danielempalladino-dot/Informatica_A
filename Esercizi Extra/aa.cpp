#include <stdio.h>
#define N 8
#define M 9

typedef struct {
	int x;
	int y;
	char dir [20];
} punto;

void cercaParola (char M[N][N], char v[], punto *p);

int main(){
	int i,k; 
    char G[N][N]={'B','R','I','S','A','T','A','B',
                    'A','A','R','A','N','C','I','A',
                    'N','C','I','P','O','L','L','A',
                    'A','V','I','O','L','I','N','O',
                    'N','R','A','T','O','R','T','A',
                    'A','V','O','L','A','N','T','E',
                    'D','I','S','C','O','R','S','O',
                    'A','N','A','T','R','A','V','O'};
    char P[M][M]={'R','I','S','A','T','A','\0','\0','\0',
              'A','R','A','N','C','I','A','\0','\0',
              'B','A','N','A','N','A','\0','\0','\0',
              'C','I','P','O','L','L','A','\0','\0',
              'V','I','O','L','I','N','O','\0','\0',
              'T','O','R','T','A','\0','\0','\0','\0',
              'V','O','L','A','N','T','E','\0','\0',
              'D','I','S','C','O','R','S','O','\0',
              'A','N','A','T','R','A','\0','\0','\0'};
                    
    printf("Matrice caratteri\n");                
    for(i=0;i<N;i++){
    	for(k=0;k<N;k++){
    		printf("%c ",G[i][k]);
		}
		printf("\n");
	}         
    printf("\nParole\n");                
    for(i=0;i<M;i++){
    	printf("%s",P[i]);
		printf("\n");
	}         
	/*SCRIVERE QUI LE CHIAMATE DI FUNZIONI E I COMANDI DI STAMPA*/
	
	
	return 0;
}



