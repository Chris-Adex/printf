#include "main.h"

void print_buffer(char buffer[], int *buff_index);

/**
 * _printf - printf function
 * @format: character string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, printd = 0, pchars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != 0; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			pchars++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printd = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printd == -1)
				return (-1);
			pchars += printd;
		}
	}

	print_buffer(buffer, &buff_index);

	va_end(list);

	return (pchars);
}

/**
 * print_buffer - prints buffer contents if it exist
 * @buffer: chars array
 * @buff_index: index to add next char (length)
 */

void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
