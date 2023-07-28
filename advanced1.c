#include "main.h"

/**
 * print_unsigned - prints an unsigned int
 * @args: a va_list argument
 */
void print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *num_str = convert(num, 10);

	write(1, num_str, strlen(num_str));
	free(num_str);
}

/**
 * print_octal - print an octal number
 * @args: a va_list argument
 */
void print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *num_str = convert(num, 8);

	write(1, num_str, strlen(num_str));
	free(num_str);
}

/**
 * print_hex - prints a number in hex
 * @args: a va_list argument
 */
void print_hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *num_str = convert(num, 16);

	write(1, num_str, strlen(num_str));
	free(num_str);
}

/**
 * print_HEX - prints Hex numbers in uppercase
 * @args: a va_list argument
 */
void print_HEX(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *num_str = convert(num, 16);
	int i;

	for (i = 0; num_str[i]; i++)
		num_str[i] = toupper(num_str[i]);
	write(1, num_str, strlen(num_str));
	free(num_str);
}
