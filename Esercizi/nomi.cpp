#include <stdio.h>
int main ()
{
	char nome;
	printf("Dimmi chi sei\na = adriel \nd = daniele\nv = valeria\ne = emanuele\n");
	scanf("%c",&nome);
	if (nome == 'a')
	{
		printf("sei un albanese di merda");
		return 0;
	}
	if (nome == 'd')
	{
		printf("hai il cazzo piccolo");
		return 0;
	}
	if (nome == 'v')
	{
		printf("sei bellissima");
		return 0;
	}
	if (nome ==  'e')
	{
		printf("sei molto generoso");
	}
	else printf("non so chi tu sia");
	return 0;
}
