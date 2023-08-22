#include "main.h"
/**
 * get_width - calculates the width for printing
 * @format: formatted string in which to print the arguments
 * @i: list of arguments to be printed
 * @list: list of arguments
 * Return: wid
 */
int get_width(const char *format, int *i, va_list list)
{
	int current_i;
	int wid = 0;

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		if (is_digit(format[current_i]))
		{
			wid *= 10;
			wid += format[current_i] - '0';
		}
		else if (format[current_i] == '*')
		{
			current_i++;
			wid = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = current_i - 1;

	return (wid);
}
