#include "shell.h"

/**
 * print_number - print a number
 * @n: number to print
 *
 * Return: void
 */

void print_number(int n)
{
	char ni = NULL;

	if (n > 9)
	{
		print_number(n / 10);
		ni = ('0' + (n % 10));
		write(2, &ni, 1);
	}
	else
	{
		ni = '0' + n;
		write(2, &ni, 1);
	}
}
