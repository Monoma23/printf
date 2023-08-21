#include "main.h"
void printt_buf(char buff[], int *_ind);

/**
 * _printf - printf funct
 * @format: formatt
 * Return:affichee c
 */
int _printf(const char *format, ...)
{
int h, affichee = 0, charac_affiche = 0;
int flagss, wid, precis, size, _ind = 0;
va_list list;
char buff[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(list, format);

for (h = 0; format && format[h] != '\0'; h++)
{
if (format[h] != '%')
{
buff[_ind++] = format[h];
if (_ind == BUFF_SIZE)
printt_buf(buff, &_ind);
charac_affiche++;
}
else
{
printt_buf(buff, &_ind);
flagss = get_flags(format, &h);
wid = get_width(format, &h, list);
precis = get_precis(format, &h, list);
size = get_size(format, &h);
++h;
affichee = handle_print(format, &h, list, buff,
flagss, wid, precis, size);
if (affichee == -1)
return (-1);
charac_affiche += affichee;
}
}

printt_buf(buff, &_ind);

va_end(list);

return (charac_affiche);
}

/**
 * printt_buf - Prints contents of the buff in case it exists
 * @buff: array of chars
 * @_ind: Index where to add next char, represents the len
 */
void printt_buf(char buff[], int *_ind)
{
if (*_ind > 0)
write(1, &buff[0], *_ind);

*_ind = 0;
}

