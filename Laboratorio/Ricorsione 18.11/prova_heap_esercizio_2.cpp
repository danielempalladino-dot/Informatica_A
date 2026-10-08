#include <stdlib.h>
#include <stdio.h>
#define N 5
int main()
{
	int *p = NULL;
	int i=0;
	p = (int*)malloc(sizeof(int)*5);
	for(i=0; i<N; i++)
		scanf("%d", &p[i]);
	for(i=0; i<N; i++)
		printf("%d,", p[i]);
}
