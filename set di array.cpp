//set di un array, numeri univoci che ho inserito --> numeri inseriti senza ripetizioni
#include <stdio.h> 
int main()
{
	int real_n, i, j, N = 100, set[N], last_number,last_set = 0,flag = 0;
	do
	{
		printf("inserisci un numero: ");
		scanf(" %d", &real_n);
		//definisco quante cifre voglio inserire
	}
	while((real_n<=0) ||(real_n>N));
	for(i=0; i<real_n; i++) //ciclo che gira per quanti numeri ho deciso di inserie (< della lunghezza dell'array)
	{
		flag = 0;
		scanf(" %d", &last_number);
		for(j=0; j<last_set; j++)//questo for confronta tutte le celle dell'array usate fino ad ora (last_set) 
		{
			if (set[j]==last_number) //VERIFICA CHE LA CIFRA NON SIA GIA INSERITA --> se non è presente, flag è vera 
			{
				flag = 1;
				break;
			}
		}
		if (!flag) //flag è vera quando il numero non è nel set
		{
			set[last_set] = last_number;
			last_set++;
		}
	}
	printf("{");
	for(i=0; i<last_set; i++)
	{
		printf("%d ", set[i]);
	}
	printf("}");
	
}
