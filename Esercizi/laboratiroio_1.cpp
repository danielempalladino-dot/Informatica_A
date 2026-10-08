#include <stdio.h>
int main ()
{
	char a, b, c;
	printf("inserisci tre caratteri minuscoli e diversi tra loro\n");
	scanf(" %c", &a);
	scanf(" %c", &b);
	scanf(" %c", &c);
	if ((a<b)&&(a<c))
	{
		if (b<c)
			printf("\n%c,%c,%c", a,b,c);
		else
			printf("\n%c,%c,%c", a,c,b);
	return 0;
	}
	if ((b<a)&&(b<c))
	{
		if (a<c)
			printf("\n%c,%c,%c", b,a,c);
		else
			printf("\n%c,%c,%c", b,c,a);
	return 0;
	}
	if ((c<a)&&(c<b))
	{
		if (a<b)
			printf("\n%c,%c,%c", c,a,b);
		else 
			printf("\n%c,%c,%c", c,b,a);
	return 0;
	}
	else printf("carattere non riconosciuto!");
	return 0;
}
