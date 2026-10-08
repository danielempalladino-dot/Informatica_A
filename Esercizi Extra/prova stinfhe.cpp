#include<stdio.h>
#include<string.h>
#define N 100


typedef char Stringa[N];
int verifica( Stringa parola, Stringa acronimo);
int main(){
	int v=0;

    Stringa acr1="ATM", txt1 = "Azienda Trasporti Milanesi"; //SI
    Stringa acr2="AT", txt2 = "Azienda Trasporti Milanesi";  //NO
    Stringa acr3="ATM", txt3 = "Azienda Trasporti Lombardi"; //NO
    Stringa acr4="ATMK", txt4 = "Azienda Trasporti Milanesi";//NO
    Stringa acr5="ATM", txt5 = "Azienda Trasporti Milanesi Lombardi"; //NO
	
    // TODO: invocazione della funzione e stampa risultato
	v=verifica(txt1, acr1);
	if(v==0)
		printf("si\n");
	else printf("no\n");
	v=verifica(txt2, acr2);
	if(v==0)
		printf("si\n");
	else printf("no\n");

}

int verifica(Stringa parola, Stringa acronimo)
{
	int i=0, j=0, r;
	Stringa iniziali;
	for(i=0; parola[i]=!'\0'; i++)
		if (i=0 || parola[i-1] == ' ')
		{
			iniziali[j] = parola[i];
		}
	r = strcmp(iniziali, acronimo);
	return r;
}
// TODO: funzione (? vietato stampare nella funzione)

