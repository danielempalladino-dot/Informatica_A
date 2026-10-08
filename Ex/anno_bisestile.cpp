#include <stdio.h>
int main ()
{
	int anno;
	printf("Dimmi un anno e ti diro' se e' bisestile:\n");
	scanf("%d", &anno);
	if(anno%400 == 0)
	{
		printf("Complimenti! L'anno selezionato e' bisestile");
		return 0;
	}
	if (anno%4==0)
	{
		if(anno%100==0)
		{
			printf("Mi dispiace, l'hanno selezionato non e' bisestile");
		} 
		else printf("Complimenti! L'anno selezionato e' bisestile");
	}
	else printf("Mi dispiace, l'hanno selezionato non e' bisestile");
	
}
