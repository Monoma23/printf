#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsignedd - Prints an unsigned num
 * @types: List a of args
 * @buffer: Buffer array handle print
 * @flagss:  Calculates active flagss
 * @wid: get wid
 * @precis: precis specification
 * @size: Size spec
 * Return: Number of chars printd
 */
int print_unsignedd(va_list types, char buffer[],
int flagss, int wid, int precis, int size)
{
int k = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);

num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[k--] = '0';
buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[k--] = (num % 10) + '0';
num /= 10;
}
k++;
return (write_unsgnd(0, k, buffer, flagss, wid, precis, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flagss:  Calculates active flagss
 * @wid: get wid
 * @precis: precis specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
int flagss, int wid, int precis, int size)
{
int k = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(wid);

num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[k--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[k--] = (num % 8) + '0';
num /= 8;
}

if (flagss & F_HASH && init_num != 0)
buffer[k--] = '0';

k++;

return (write_unsgnd(0, k, buffer, flagss, wid, precis, size));
}

/************** PRINT UNSIGNED NUM IN HEXADECIMAL **************/
/**
 * print_hexad - Prints an unsigned number in hexadecimal notation
 * @types: List of args
 * @buffer: Buffer array to handle print
 * @flagss:  Calculates active flagss
 * @wid: get wid
 * @precis: precis specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexad(va_list types, char buffer[],
int flagss, int wid, int precis, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flagss, 'x', wid, precis, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flagss:  Calculates active flagss
 * @wid: get wid
 * @precis: precis specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
int flagss, int wid, int precis, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flagss, 'X', wid, precis, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flagss:  Calculates active flagss
 * @flag_ch: Calculates active flagss
 * @wid: get wid
 * @precis: precis specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
int flagss, char flag_ch, int wid, int precis, int size)
{
int k = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(wid);

num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[k--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[k--] = map_to[num % 16];
num /= 16;
}

if (flagss & F_HASH && init_num != 0)
{
buffer[k--] = flag_ch;
buffer[k--] = '0';
}

k++;
return (write_unsgnd(0, k, buffer, flagss, wid, precis, size));
}

