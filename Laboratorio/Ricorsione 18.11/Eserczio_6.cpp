/*Data la struct che definisce un numero complesso:

typedef struct Complex{ double Re, Im; } Complex;

Si definisca una funzione GetComplesso(Complex * n); che legga da terminale un numero complesso e lo salvi nella struttura passata per riferimento.

Si definisca una funzione double Modulo(Complex * n); che restituisca il modulo di un numero complesso passato per riferimento.

Si definisca una funzione RICORSIVA che riceve un array di complessi e restituisce il numero complesso di modulo massimo.

Complex MaxComplessoModulo(Complex * array);

Nota: se necessario, si aggiungano alle funzioni ulteriori parametri
*/
#include <stdio.h>
#include <math.h>
#define N 3
typedef struct Complex{ double Re, Im; } Complex;

void getComplesso(Complex *n);
double Modulo(Complex *n);
Complex MaxComplessoModulo(Complex v[], int l);

int main()
{
	int i;
	Complex mod;
	Complex n[N];
	for(i=0; i<N; i++)
		getComplesso(&n[i]);
	mod = MaxComplessoModulo(n, i);
	printf("\n%.2lf, %.2lf", mod.Re, mod.Im);
}

void getComplesso(Complex *n)
{
	printf("Inserisci parte reale: ");
	scanf("%lf", &n->Re);
	printf("Inserisci parte immaginaria: ");
	scanf("%lf", &n->Im);
	printf("Il tuo numero reale e': %.2lfx, %.2lfiy", n->Re, n->Im);
}

double Modulo(Complex *n)
{
	double mod;
	mod = sqrt(pow(n->Re, 2)+pow(n->Im, 2));
	return mod;
}

Complex MaxComplessoModulo(Complex v[], int l)
{
	if (l == 1)
		return v[0];
		
	Complex maxRest = MaxComplessoModulo(v, l-1);
	
	if(Modulo(&v[l-1])>Modulo(&maxRest))
		return v[l-1];
	else 
		return maxRest;
}
