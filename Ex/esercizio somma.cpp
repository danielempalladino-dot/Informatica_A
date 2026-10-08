#include <stdio.h>
int main (){
	int a, b, c, d;
	printf("dimmi i 4 numeri \n");
	scanf("%d%d%d%d", &a, &b, &c, &d);
	//scanf("%d,&d,%d,&d", &a, &b, &c, &d); ATTENZIONE --> non si mettono le virgole quando definisci la tipologia di imput
	a= (a+b)*(c+d);
	printf("\n \n il risultato e': %d", a);
	return 0;
}
