#include <stdio.h>
int main(){
	printf("in che unita di misura hai la temperatura? \n");
	char unit;
	scanf(" %c", &unit);
	if (unit == 'f')
	{
		float f, c;
		printf("che temperatura c'e' in fahrenheit? \n");
		scanf("%f", &f);
		c= ((f-32)*5.0)/9;
		printf("\necco la temperatura in celsius: %.2f C", c);
		//printf non ha bisogno dell'associazione tramite &, basta semplicemente la virgola 
		return 0;
	}
	if (unit == 'c')
	{
		float f, c;
		printf("che temperatura c'e' in celsius? \n");
		scanf("%f", &c);
		f= ((9*c)/5.0)+25 ;
		printf("\necco la temperatura in Fahrenheit: %.2f F", f);
		return 0;
	}
	else
	{
		printf("unita di misura non riconosciuta!");
		return 0;
	}
}

