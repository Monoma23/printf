#include "main.h"

/**************** PRINT POINTER *****************/
/**
 * print_ptr - Print value of a ptr variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flagss:  Calculates active flagss
 * @wid: get wid
 * @precis: precis specification
 * @size: Size specifier
 * Return: Number of chars printd
 */
int print_ptr(va_list types, char buffer[],
int flagss, int wid, int precis, int size)
{
char super_c = 0, padd = ' ';
int ind = BUFF_SIZE - 2, longueur = 2, pad_startt = 1;
unsigned long nbr_address;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);

UNUSED(wid);
UNUSED(size);

if (addrs == NULL)
return (write(1, "(nil)", 5));

buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precis);

nbr_address = (unsigned long)addrs;

while (nbr_address > 0)
{
buffer[ind--] = map_to[nbr_address % 16];
nbr_address /= 16;
longueur++;
}

if ((flagss & F_ZERO) && !(flagss & F_MINUS))
padd = '0';
if (flagss & F_PLUS)
super_c = '+', longueur++;
else if (flagss & F_SPACE)
super_c = ' ', longueur++;

ind++;

/*return (write(1, &buffer[h], BUFF_SIZE - h - 1));*/
return (write_pointer(buffer, ind, longueur,
wid, flagss, padd, super_c, pad_startt));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flagss:  Calculates active flagss
 * @wid: get wid
 * @precis: precis specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
int flagss, int wid, int precis, int size)
{
int h = 0, offseto = 0;
char *str = va_arg(types, char *);

UNUSED(flagss);
UNUSED(wid);
UNUSED(precis);
UNUSED(size);

if (str == NULL)
return (write(1, "(null)", 6));

while (str[h] != '\0')
{
if (is_print(str[h]))
buffer[h + offseto] = str[h];
else
offseto += append_hexa_cod(str[h], buffer, h + offseto);

h++;
}

buffer[h + offseto] = '\0';

return (write(1, buffer, h + offseto));
}

/************************* PRINT REVERSE *************************/
/**
 * print_revers - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flagss:  Calculates active flagss
 * @wid: get wid
 * @precis: precis specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_revers(va_list types, char buffer[],
	int flagss, int wid, int precis, int size)
{
char *str;
int h, countt = 0;

UNUSED(buffer);
UNUSED(flagss);
UNUSED(wid);
UNUSED(size);

str = va_arg(types, char *);

if (str == NULL)
{
	UNUSED(precis);

	str = ")Null(";
}
for (h = 0; str[h]; h++)
	;

for (h = h - 1; h >= 0; h--)
{
char z = str[h];

write(1, &z, 1);
countt++;
}
return (countt);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13str - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flagss:  Calculates active flagss
 * @wid: get wid
 * @precis: precis specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13str(va_list types, char buffer[],
int flagss, int wid, int precis, int size)
{
char x;
char *str;
unsigned int h, j;
int countt = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flagss);
UNUSED(wid);
UNUSED(precis);
UNUSED(size);

if (str == NULL)
str = "(AHYY)";
for (h = 0; str[h]; h++)
{
	for (j = 0; in[j]; j++)
	{
	if (in[j] == str[h])
	{
		x = out[j];
		write(1, &x, 1);
		countt++;
		break;
	}
	}
	if (!in[j])
	{
		x = str[h];
		write(1, &x, 1);
		countt++;
	}
}
return (countt);
}

