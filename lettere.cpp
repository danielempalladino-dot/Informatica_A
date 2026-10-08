#include <stdio.h>
int main ()
{
	char lettera, prox_lettera;
	printf("inserisci una lettera\n");
	scanf(" %c", &lettera);
	if ((lettera<'A'&&1>'Z')||(1<'a'&&1>'z'))
	{
		return 0;
	}
	if (lettera == 'z' || lettera == 'Z')
		prox_lettera=lettera;
	else
	{
		prox_lettera =  lettera +1;
		printf("next di %c e' %c\n", lettera, prox_lettera);
	}
}
