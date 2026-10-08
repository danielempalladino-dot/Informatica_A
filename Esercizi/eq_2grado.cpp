#include <stdio.h>
#include<math.h>
int main ()
{
	float a,b,c,delta,x1,x2;
	printf("inserisci a: ");
	scanf(" %f", &a);
	printf("\nOra iserisci b: ");
	scanf(" %f", &b);
	printf("\nOra inserisci c: ");
	scanf(" %f", &c);
	delta = (b*b)-(4*a*c);
	printf("\nDelta = %f", delta);
	if (delta >=0)
	{
		if (delta>0)
		{
			x1 = (-b-sqrt(delta))/(2*a);
			x2 = (-b+sqrt(delta))/(2*a);
			printf("\nx1 = %.2f\nx2 = %.2f", x1, x2);
			return 0;
		}
		else 
		{
			x1= (-b)/(2*a);
			printf("\nLa tua equazione e' un quadrato:\nx1,2 = %.2f", x1);
			return 0;
		}
	}
	printf("\nIl delta e' negativo, non ci sono soluzioni!");
	return 0;
}
