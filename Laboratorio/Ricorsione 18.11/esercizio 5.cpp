/*Si codifichi una funzione RICORSIVA che confronta due stringhe

int strRecursiveCmp( char* s1, char* s2 );

e, così come la funzione di libreria strcmp()), restituisce:
- 0: se le due stringhe sono uguali
- un numero negativo (ad es. -1): se s1 precede alfabeticamente s2
- un numero negativo (ad es. 1) : se s1 segue alfabeticamente s2*/
#include <stdio.h>
#define N 50
int strRecursiveCmp(char *s1, char *s2);

int main()
{
	int flag = 2;
	char s1[N], s2[N];
	fgets(s1, N, stdin);
	fflush(stdin);
	fgets(s2, N, stdin);
	flag = strRecursiveCmp(s1, s2);
	printf("\n%d", flag);
}

int strRecursiveCmp(char *s1, char *s2)
{
	int static i = 0;
	if (s1[i] == '\0' || s2[i] == '\0')
	{
		if (s1[i]==s2[i])
			return 0;
		if(s1[1]=='\0')
			return -1;
		else if(s2[i]=='\0')
			return 1;
	}
			
	int flag = strRecursiveCmp(&s1[i+1], &s2[i+1]);
	
	if (flag == 0)
	{
		if(s1[i] == s2[i])
			return 0;
		if(s1[i]<s2[i])
			return -1;
		else
			return 1;
	}
}
