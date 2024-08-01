#include "main.h"

/**
 * get_precision - determines precision for printing
 * @format: formatted string
 * @i: list of arguments to be printed
 * @args: list of arguments
 *
 * Return: precision.
 */

int get_precision(const char *format, int *i, va_list args)
{
	int y = *i + 1;
	int precision = -1;

	if (format[y] != '.')
		return (precision);

	precision = 0;

	for (y += 1; format[y] != '\0'; y++)
	{
		if (is_digit(format[y]))
		{
			precision *= 10;
			precision += format[y] - '0';
		}
		else if (format[y] == '*')
		{
			y++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = y - 1;

	return (precision);
}
