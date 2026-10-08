#include <stdio.h>
int main ()
{
	int c=0;
	char carattere;
	scanf(" %c", &carattere);
	while (carattere != '*')
	{
		c++;
		printf("%c , %d\n", carattere, c);
		scanf(" %c", &carattere);
	}
	return 0;
}
