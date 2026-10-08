#include <stdio.h>
int main()
{
	//per stampare l'indirizzo di memoria si usa %p
	int *pa, a = NULL;
	pa = &a;
	scanf("%d", pa);
	//scanf vuole l'indirizzo della casella, per questo basta il puntatore
	*pa *= 2;
	printf("%d\n", *pa);
	//printf invece vuole il valora della cella, quindi serve l'asterisco
	printf("%p\n",pa);
	//stampo l'indirizzo della cella a, sarebbe stato equivalente scrivere pa al posto di aa
}
