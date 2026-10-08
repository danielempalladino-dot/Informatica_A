#include <stdio.h>
#include <stdlib.h>

int main()
{
	int q = 0;
	FILE *file = NULL;
	file=fopen("prova.txt", "r");
	if(file == NULL)
	{
		printf("ERRORE");
		return 1;
	}
	if(file!=NULL)
	{
		fscanf(file, "%d", &q);
		printf("%d", q);
	}
}
