#include<stdio.h>
#define N 5

void stampa(int v[], int l);
void riordina (int u[], int l1, int v[], int l2);
int main()
{
    int u[N] = {4,1,3,7,0}, v[N] = {1,6,8,4};


    // TODO stampa u e v
	stampa(u, 5);
	stampa(v, 4);

    // TODO invocazione riordina
	riordina(u, 5, v, 4);

    // TODO stampa u dopo invocazione
	stampa(u, 5);

    return 0;
}

void stampa(int v[], int l)
{
	int i=0;
	for(i=0;i<l;i++)
		printf("%d,", v[i]);
	printf("\n");
}

void riordina(int u[], int l1, int v[], int l2)
{
	int i=0, j=0, k=0, w=0, flag = 0, tempv[N], tempu[N];
	for(i=0;i<l1;i++)
	{
		for(j=0;j<l2 && flag == 0;j++)
			if(u[i] == v[j])
			{
				tempv[k]=v[j];
				k++;
				flag = 1;
			}
		if(flag == 0)
		{
			tempu[w]=u[i];
			w++;
		}
		flag = 0;
	}
	for (i=0; i<w; i++)
		u[i]=tempu[i];
	for(i;i<w+k;i++)
		u[i]=tempv[i-w];
}
	

