#include "main.h"

/**
 * get_flags - determine active flags
 * @format: formatted string
 * @i: parameter
 *
 * Return: flags
 */

int get_flags(const char *format, int *i)
{
	int x, y;
	int flags = 0;
	const char flags_char[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flags_arr[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (y = *i + 1; format[y] != '\0'; y++)
	{
		for (x = 0; flags_char[x] != '\0'; x++)
			if (format[y] == flags_char[x])
			{
				flags |= flags_arr[x];
				break;
			}
		if (flags_char[x] == 0)
			break;
	}
	*i = y - 1;
	return (flags);
}
