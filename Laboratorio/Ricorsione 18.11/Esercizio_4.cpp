/*Si codifichi una funzione RICORSIVA

intis_power( int n, int b )

che controlla se un numero intero n è una potenza del numero intero b, restituendo 0 o 1.

Per farlo, si consideri la seguente proprietà: n è una potenza di b se è divisibile per b e inoltre n/b è a sua volta una potenza di b.

Si badi ad operare correttamente anche nei casi b=0, b=1.
*/
#include <stdio.h>
int is_power(int n, int b);
int main()
{
	int n,b, k;
	printf("inserisci i due valori:\nn: ");
	scanf("%d", &n);
	printf("b: ");
	scanf("%d", &b);
	k = is_power(n,b);
	if(k==1)
		printf("Non e' potenza");
	else if(k==0) 
		printf("e' potenza");
}

int is_power(int n, int b)
{
	if (b==0)
	{
		if (n==0)
			return 0;
		return 1;
	}
	if (b==1)
	{
		if(n==1)
			return 0;
		return 1;
	}
	if (b%n != 0)
		return 1;
	if (b/n == 1)
		return 0;

	else 
	{
		int k = b/n;
		is_power(n,k);
	}
}

