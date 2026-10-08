#include <stdio.h>
int main ()
{
	float op1, op2, res;
	char operazione;
	scanf(" %f", &op1);
	scanf(" %f", &op2);
	scanf(" %c", &operazione);
	switch(operazione)
	{
		case '+':
			res = op1 + op2;
			break;
		case '-':
			res = op1 - op2;
			break;
		case '/':
			if (op2 != 0)
				res = op1  / op2;
			else 
			{
				printf("Errore");
				return 1;
			}
			break;
		case '*':
			res = op1 * op2;
			break;
		default:
		{
			printf("operazione non riconosciuta!");
			return 2;
		}
	}
	printf("%.2f %c %.2f = %.2f", op1, operazione, op2, res);	
}
