#include "main.h"
/**
 * handle_print - Prints an arg based on its typ
 * @fmtt: Formatted str in which to print args
 * @list: List of args to be prind
 * @ind: ind
 * @buffer: Buffer array to handle print
 * @flagss: Calcul act flag
 * @wid: get wid
 * @precis: precis specifi
 * @size: Size specifir
 * Return: 1 or 2;
 */
int handle_print(const char *fmtt, int *ind, va_list list, char buffer[],
int flagss, int wid, int precis, int size)
{
int i, unknow_len = 0, printed_chars = -1;
fmtt_t fmt_types[] = {
{'c', print_charachter}, {'s', print_str}, {'%', print_percnt},
{'i', print_integ}, {'d', print_integ}, {'b', print_binar},
{'u', print_unsignedd}, {'o', print_octal}, {'x', print_hexad},
{'X', print_hexa_upper}, {'p', print_ptr}, {'S', print_non_printable},
{'r', print_revers}, {'R', print_rot13str}, {'\0', NULL}
};
for (i = 0; fmt_types[i].fmtt != '\0'; i++)
		if (fmtt[*ind] == fmt_types[i].fmtt)
			return (fmt_types[i].fn(list, buffer, flagss, wid, precis, size));

if (fmt_types[i].fmtt == '\0')
	{
		if (fmtt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmtt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (wid)
		{
			--(*ind);
			while (fmtt[*ind] != ' ' && fmtt[*ind] != '%')
				--(*ind);
			if (fmtt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmtt[*ind], 1);
		return (unknow_len);
	}
return (printed_chars);
}

