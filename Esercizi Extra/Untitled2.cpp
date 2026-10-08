#include <stdio.h>
#include <ctype>
#define M 100
char conta (const char parole[M])
{
	int frequenze [26] = {0};
	int i =0 ;
	char lettura;
	while (s[i]!= '\0')
	{
		if (i==0 || s[i-1] = ',' && isalpha (s[i]))
		{
			lettera = s[i];
			frequenze [lettera - 'a']++;
		}
		i++;
	}
	int max = 0
	for (i=0; i<25;i++)
	{
		if (max<frequenze [i])
			lettera = i +'a';
	}
	return lettera
}
void elimina (char S[], char T[], char c)
{
	int l = strlen (s);
	int i = 0;
	int j = 0;
	int prima = 1;
	
	while (i<l)
	{
		if (i==0 || s[i-1] = ',')
		{
			if (s[i] == c )
			{
				if(!prima)
				{
					T[j]=',';
					j++;
				}
				while (s[i]!=',' && s[i] != '\0')
				{
					T[j] = s[i];
					i++;
					j++;
				}
			}
		}
	}
	prima = 0;
}
int main ()
{
	
}
