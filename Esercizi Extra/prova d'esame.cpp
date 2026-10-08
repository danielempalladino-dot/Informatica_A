#include <stdio.h>


#define N 100
#define M 8

typedef char Stringa[N];
typedef struct {int x,y;} Punto; 
void stampapercorso(Punto p[], int lung);
int pulisci(Punto p[], Punto q[], int lung);
//scrivere qui i prototipi delle funzioni richieste
char finale(char mat[8][8], Punto p[], int i);

int main(){
	Punto per1[100]={{0,0},{0,-4},{2,6},{4,5},{3,1},{7,2},{8,2},{2,-4}};
	Punto per2[100];
	int lung1=8,lung2=0, i=0;
	char mat[M][M]={'B','R','S','P','E','E','F','A',
                    'Y','V','K','W','F','H','H','W',
                    'J','C','S','I','E','R','R','F',
                    'F','V','C','P','L','N','B','Q',
                    'P','C','D','F','Y','A','O','P',
                    'C','G','W','S','C','Q','O','O',
                    'D','H','H','S','L','L','U','I',
                    'X','R','O','L','E','N','T','Y'};
    Stringa str;
    
	stampapercorso(&per1[0], lung1); //mi serve un puntatore alla prima casella
	lung2 = pulisci(&per1[0], &per2[0], lung1);
	printf("\n");
	stampapercorso(&per2[0], lung2);
	printf("\n");
	for(i=0;i<lung2; i++)
	{
		str[i]= finale(mat, per2, i);
		printf("%c", str[i]);
	}
	
	//scrivere qui le chiamate a funzione
	
}
void stampapercorso(Punto p[], int lung)
{
	int i=0;
	for(i=0; i<lung; i++)
	{
		printf("(%d, %d)", p[i].x, p[i].y);
	}
}
int pulisci(Punto p[], Punto q[], int lung)
{
	int i = 0, j=0, lung2=0;
	for(i=0; i<lung; i++)
		if((p[i].x>-1 && p[i].x<8)&&(p[i].y >-1 && p[i].y <8))
		{
			q[j].x = p[i].x;
			q[j].y = p[i].y;
			j++;
			lung2++;
		}
	return lung2;
}
char finale(char mat[8][8], Punto p[], int i)
{
	char lettera;
	lettera = mat[p[i].x][p[i].y];
	return lettera;
}
//scrivere qui le funzioni richieste




