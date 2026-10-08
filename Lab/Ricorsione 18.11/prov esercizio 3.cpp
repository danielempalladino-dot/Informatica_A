#include <stdio.h>
#define N 50
int main()
{
	char s[N];
	int i=0;
	fgets(s, N, stdin);
	for(i=0;s[i]!='\0'; i++)
		if(s[i]== ' ')
		{
			int j=i;
			for(j; s[j]!='\0'; j++)
				s[j] = s[j+1];
			i--;
		}
	printf("%s", s);
}
