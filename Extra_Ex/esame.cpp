#include <stdio.h>
#include <string.h>
#define N 10

typedef struct {
    char piatto[100];
    int calorie;
} portata;


typedef struct {
    portata primo;
    portata secondo;
    portata frutta;
    portata dolce;
} pasto;


typedef struct {
    pasto menu[10];
    int numPasti;
} menu;

void stampaMenu (menu f);
void sommePasti (menu f, int sum[]);
int eliminaPastiipercalorici(menu *f);

int main(void) {
	int somma[N], i=0, eliminati; //somma di N poiche ho definito N = 10 ovvero il numero massimo di pasti all'interno di un menu
    menu m = {
        {{{"Risotto ai funghi",720},{"Salmone al forno",520},{"Pera",95},{"Panna cotta",360} },
         {{"Penne al pesto",700},{"Vitello tonnato",560},{"Banana",105},{"Cheesecake",430} },
         {{"Minestrone",250},{"Bresaola rucola",300},{"Arancia",70},{"Sorbetto",160} },
         {{"Maccheroni ala gricia",950},{"Costata di manzo",850},{"Mela",80},{"Tiramisu",420} },
         {{"Lasagne",820},{"Costata di manzo",850},{"Kiwi",60},{"Cannolo",440} },
         {{"Gnocchi burro e salvia",680},{"Orata alla piastra",410},{"Fragole",50},{"Gelato",220} }
        },6};
    stampaMenu(m);
    sommePasti(m, somma);
    
    //stampo le calorie ottenute con sommaPasti
    printf("\n-- Somme Caloriche Per Pasto --\n\n");
    for(i=0; i<m.numPasti; i++)
    	printf("Pasto numero %d:\t %d kcal\n", i+1, somma[i]);
    	
    //invoco la funzione eliminapastiipercalorici (int) e assegno il numero di pasti eliiminati alla variabile eliminati
	eliminati = eliminaPastiipercalorici(&m); 
	printf("\n-- Menu dopo aver eliminato i pasti ipercalorici (%d rimossi) --\n", eliminati);
	stampaMenu(m);
    return 0;
}

void stampaMenu (menu f)
{
	int i=0;
	printf("\n--Menu di Oggi--\n");
	for(i=0;i<f.numPasti; i++) //indice i deve andare da 0 al numero di pasti presenti nel menu
	{
		printf("\nPasto numero %d:\n", i+1);
		printf("Primo: %s \t %d\n", f.menu[i].primo.piatto, f.menu[i].primo.calorie);
		printf("Secondo: %s \t %d \n", f.menu[i].secondo.piatto, f.menu[i].secondo.calorie);
		printf("Frutta: %s \t %d \n", f.menu[i].frutta.piatto, f.menu[i].frutta.calorie);
		printf("Dolce: %s \t %d \n", f.menu[i].dolce.piatto, f.menu[i].dolce.calorie);
	}
}

void sommePasti (menu f, int sum[])
{
	int i=0;
	for(i=0; i<f.numPasti; i++)
		sum[i] = f.menu[i].primo.calorie + f.menu[i].secondo.calorie + f.menu[i].frutta.calorie + f.menu[i].dolce.calorie; 
		//faccio la somma di tutte le calorie di ogni portata del pasto
}

int eliminaPastiipercalorici(menu *f)
{
	int i=0, j=0, cont=0, max=2000, somma[N]; 
	sommePasti(*f,somma); //uso la funzione che ho definito sommePasti per ottenere la somma calorica di ogni pasto
	for(i=0;i<f->numPasti;i++)
	{
		if(somma[i]>max) //condizione per cui la somma del pasto deve essere minore a 2000 kcal = max, utilizzo il ciclo for per scorrere il vettore di interi somma.
		{
			for(j=0;j<f->numPasti-i;j++) //quando e' true "sposto di uno a sinistra tutte le altre portate del mio menu"
				f->menu[i+j] = f->menu[i+j+1];
			cont++;  //uso cont per tenere conto di quanti pasti elimino cosi poi da restituirli al main
		}
	}
	f->numPasti = f->numPasti-cont; //modifico il mio indice di numpasti cosi da avere un menu ben formato
	return cont; 
}
