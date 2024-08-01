#include "main.h"

/**
 * get_size - determines the size to cast on the argument
 * @format: formatted string
 * @i: list of arguments to print
 *
 * Return: size
 */

int get_size(const char *format, int *i)
{
	int y = *i + 1;
	int size = 0;

	if (format[y] == 'l')
		size = S_LONG;
	else if (format[y] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = y - 1;
	else
		*i = y;

	return (size);
}
