#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
/* FLAGSs */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZESs */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmtt - Struct op
 *
 * @fmtt:format.
 * @fn: The funct associat
 */
struct fmtt
{
	char fmtt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmtt fmtt_t - Struct op
 *
 * @fmtt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmtt fmtt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmtt, int *i,
va_list list, char buff[], int flagss, int wid, int preci, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and str */
int print_charachter(va_list types, char buff[],
	int flagss, int wid, int preci, int size);
int print_str(va_list types, char buff[],
	int flagss, int wid, int preci, int size);
int print_percnt(va_list types, char buff[],
	int flagss, int wid, int preci, int size);

/* Functions to print nums */
int print_integ(va_list types, char buff[],
	int flagss, int wid, int preci, int size);
int print_binar(va_list types, char buff[],
	int flagss, int wid, int preci, int size);
int print_unsigned(va_list types, char buff[],
	int flagss, int wid, int preci, int size);
int print_octal(va_list types, char buff[],
	int flagss, int wid, int preci, int size);
int print_hexad(va_list types, char buff[],
	int flagss, int wid, int preci, int size);
int print_hexa_upper(va_list types, char buff[],
	int flagss, int wid, int preci, int size);

int print_hexa(va_list types, char map_to[],
char buff[], int flagss, char flag_ch, int wid, int preci, int size);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buff[],
	int flagss, int wid, int preci, int size);

/* Funcion to print memory address */
int print_ptr(va_list types, char buff[],
	int flagss, int wid, int preci, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precis(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_revers(va_list types, char buff[],
	int flagss, int wid, int preci, int size);

/*Function to print a string in rot 13*/
int print_rot13str(va_list types, char buff[],
	int flagss, int wid, int preci, int size);

/* wid handler */
int handle_write_char(char c, char buff[],
	int flagss, int wid, int preci, int size);
int write_numb(int is_positive, int ind, char buff[],
	int flagss, int wid, int preci, int size);
int write_num(int ind, char bff[], int flagss, int wid, int preci,
	int length, char padd, char extra_c);
int write_pointer(char buff[], int ind, int length,
	int wid, int flagss, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buff[],
	int flagss, int wid, int preci, int size);

/****************** UTILS ******************/
int is_print(char);
int append_hexa_cod(char, char[], int);
int is_digit(char);

long int convert_size_num(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif

