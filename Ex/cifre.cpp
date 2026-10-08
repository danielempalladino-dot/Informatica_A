#include <stdio.h>
#include <math.h>
int main ()
{
	int n, temp, n_cifre = 1, res;
	printf("dammi un numero intero positivo e io ti dirò da quante cifre e' composto e il suo numero inverso\n");
	scanf("%d", &n);
	if (n<0)
		return 1;
	res = n%10; //unità
	temp = n/10; //il resto ma senza unità
	while (temp != 0)
	{
		res = res *10; //unita diventano decine la prima volta
		res = res + (temp %10); //sommo numero decine
		temp = temp / 10; //arrivo alle centinaia
		n_cifre++;
	}
	printf("Il tuo numero e' composto da %d cifre ed il suo inverso e' %d", n_cifre, res);
}
