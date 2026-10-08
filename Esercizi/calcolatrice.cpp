#include <stdio.h>
float somma(float, float);
float divisione(float,float, int *);
float diff(float,float);
float prodotto(float,float);
char leggic();
float leggin();
//teoricamente potrei gia scrivere il min ma per ora faremo prima le funzioni e dopo il main
float prodotto(float a, float b)
{
	return a*b;
}
float somma(float a, float b)
{
	return a+b;
}
float divisione(float a, float b, int*error)
{
	if(b==0)
	{
		*error = 1; //noi vogliamo l'indirizzo puntato da error, non la cella error
		return 1;
	}
	else 
		return (a/b);
}
float diff(float a, float b)
{
	return a-b;
}
char leggic()
{
	char c;
	scanf("%c", &c);
	scanf("%*c");
	return c;
}
float leggin()
{
	float n;
	scanf("%f", &n);
	scanf("%*c");
	return n;
}
int main ()
{
	int flag = 1;
	int error=0;
	float a, b, res;
	char op;
	while (flag)//equals to while (flag=1)
	{
		printf("inserisci a e b:\n");
		a = leggin();
		b = leggin();
		printf("inserisci operazione: +,-,/,*\t");
		op = leggic();
		
		switch(op)
		{
			case '+':
				res =somma (a,b);
				break;
			case '-':
				res = diff(a,b);
				break;
			case '/':
				res = divisione (a,b,&error); //ho usato la & per indiicare l'indirizzo di erorr che verra copiato
				break;
			case '*':
				res = prodotto(a,b);
				break;
			case 'q':
			case 'Q':
				flag = 0;
				break;
			default:
				printf("operazione non valida\n");
				error = 1; //cosi se l'operazione non è validanon va a stampare il risultato
		}
		if (error ==0 && flag ==1)
			printf("%.2f\n", res);
		else error = 0;
		//cosi se l'utente inserisce un operazione non valida error = 1, in questo modo non entra nel primo if
		// ma bensi nell'else --> riemposta error e riparte da capo
		//se invece inserisce q esce perche la flag = 0 esce dal while
	}	
	printf("\nProgramma terminato!");
	return 0;
}
