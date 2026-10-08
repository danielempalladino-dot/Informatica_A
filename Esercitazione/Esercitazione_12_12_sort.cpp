//come ordinare un array
//due algoritmo iterativi e uno ricorsivo

//SELECTION SORT
//doppio scorrimento


//bubble sort
//idea: sposto l'elemento piu grande in fondo all'array
//cosi ogni ciclo posso escludere gli elementi alla fine perche so che sono quelli piu grandi
//al primo ciclo sarà 1, al secondo 2, 


#include <stdio.h>
#define N 10
void bubbleSort(int [], int);
void mergeSort(int[], int start, int end);
void selectionSort(int[], int);
void stampaArray(int v[], int dim);
void copiaArray(int v[], int dest[], int dim);
void merge(int v[], int start, int end, int mid);
int main()
{
	int v[N]={2, 4, 1, 5, 6, 9, 8, 3, 15, 19};
	int t[N];
	printf("Array: ");
	stampaArray(v, N);
	printf("Selection sort: ");
	copiaArray(v, t, N);
	selectionSort(t, N);
	stampaArray(t, N);
	
	printf("bbsort: ");
	copiaArray(v, t, N);
	bubbleSort(t, N);
	stampaArray(t, N);
	
	printf("merge sort: ");
	copiaArray(v, t, N);
	mergeSort(v, 0, N-1);
	stampaArray(v, N);
	
}

void selectionSort(int v[], int dim)
{
	for(int i=0; i<dim; i++)
		for(int j=i+1; j<dim; j++)
			if(v[i]>v[j])
			{
				int temp = v[j];
				v[j] = v[i];
				v[i] = temp;
			}
}

void bubbleSort(int v[], int dim)
{
	int i, j, n_swap;
	for(i=0; i<dim-1;i++) {
	//è il limite destro della finestra
		n_swap = 0;
		for(j=0; j<dim-i-1; j++) //determina la finestra, 
		//indice j e j+1
		//parto sempre dall'inizio ma finisco ogni volta il ciclo prima
		{
			if(v[j]>v[j+1])
			{
				int temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
				n_swap++;
			}
		}
		if(n_swap == 0) break; // ciclo for delle i, se non ci sono swap è inutile continuare a scorrere l'array
	}
}

void mergeSort(int v[], int start, int end)
{
	int mid; //punto dove si splitta
	if(start < end)
	{
		mid = (start + end)/2;
		mergeSort(v, start, mid); //prima metà ricorsiva
		mergeSort(v, mid+1, end); // seconda metà ricorsiva
		merge(v, start, end, mid); //FACCIO IL MERGE
	}
}

void merge(int v[], int start, int end, int mid)
{
	int i = start, j= mid+1, k = start, copy[N];
	while(i<=mid && j<=end) //copia fino a che una non si esaurisce.
	{
		if(v[i]>v[j])
		{
			copy[k] = v[j];
			j++;
		}
		else
		{
			copy[k]=v[i];
			i++;
		}
		k++;
	}
	while(i<=mid) //se il primo while si interrompe per j
	{
		copy[k]=v[i];
		k++;
		i++;
	}
	while(j<=end) //se il primo while si interrompe per i
	{
		copy[k]=v[j];
		k++;
		j++;
	}
	for(i=start; i<=end; i++) //copio copy in v negli indici coretti per restituirlo
		v[i] = copy[i];
}

void stampaArray(int v[], int dim)
{
	printf("[");
	for(int i=0; i<dim; i++)
		printf("%d, ", v[i]);
	printf("]\n");
}

void copiaArray(int v[], int dest[], int dim)
{
	for(int i=0; i<dim; i++)
		dest[i] = v[i];
		
}
