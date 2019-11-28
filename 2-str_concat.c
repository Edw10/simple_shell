#include "shell.h"

/**
 * str_concat - concat two strings
 * @s1: string to copy
 * @s2: string to concat
 * Return: a pointer to the string
 */

char *_str_concat(char *s1, char *s2)
{
	char *p;
	int i = 0, j = 0, h = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

		while (s1[i])
		{
			i++;
		}
		while (s2[j])
		{
			j++;
		}

		p = malloc(sizeof(char) * (i + j + 2));

		if (p)
		{

			for (h = 0; h < i; h++)
			{
				p[h] = s1[h];
			}
			p[i] = '/';
			i++;
			for (h = 0; h <= j; h++)
			{
				p[i + h] = s2[h];
			}
			p[i + j] = '\0';
		}
		else
		{
			return ('\0');
		}

		return (p);

}
