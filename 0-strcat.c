#include "shell.h"

/**
 * _strcat - concatenate two strings
 * @dest: string concatenated
 * @src: string to concatenate
 *
 * Return: the concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int c[2];

	c[0] = 0;
	c[1] = 0;

	while (*(dest + c[0]) != '\0')
	{
		c[0] = c[0] + 1;
	}

	while (*(src + c[1]) != '\0')
	{
		*(dest + c[0]) = *(src + c[1]);
		c[0] = c[0] + 1;
		c[1] = c[1] + 1;

	}
	*(dest + c[0]) = *(src + c[1]);
	return (dest);
}
