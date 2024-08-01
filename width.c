#include "main.h"

/**
 * get_width - determines width
 * @format: formatted string
 * @i: list of arguments to be printed
 * @args: list of arguments
 *
 * Return: w
 */

int get_width(const char *format, int *i, va_list args)
{
	int y;
	int w = 0;

	for (y = *i + 1; format[y] != '\0'; y++)
	{
		if (is_digit(format[y]))
		{
			w *= 10;
			w += format[y] - '0';
		}
		else if (format[y] == '*')
		{
			y++;
			w = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = y - 1;

	return (w);
}
