#include <stdio.h>
int main ()
{
	float n;
	printf("Di che numero vuoi fare il modulo?\n");
	scanf(" %f", &n);
	if (n<0)
		n = -n;
	printf("%.2f", n);
}
