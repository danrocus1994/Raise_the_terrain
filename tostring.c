#include <stdio.h>
#include <stdlib.h>
#include "libs_eng.h"
/**
 *_tostring - integer to string
 *@n: the int value
 *Return: a pointer to the string
 */
char *_tostring(int n)
{
	int factor = 1, i, j, res = n;
	char *ch;

	res /= 10;
	for (i = 1; res > 0; i++)
	{
		factor *= 10;
		res /= 10;
	}
	ch = malloc((i + 1) * sizeof(char));
	if (ch == NULL)
		return (NULL);
	for (j = 1; j <= i; j++)
	{
		if (n > 9)
		{	res = n / 10;
			n = n % factor;
			while (res > 9)
				res /= 10;
		}
		else
		{       res = n;
		}
		factor /= 10;
		if (n < factor)
		{	ch[j - 1] = '0' + res;
			ch[j] = '0';
			factor /= 10;
			j++;
		}
		else
		{	ch[j - 1] =  '0' + res;
		}
	}
	ch[i] = '\0';
	return (ch);
}
