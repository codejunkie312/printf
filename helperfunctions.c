#include "main.h"

/**
 * print_char - prints a character
 * @args: A va_list of arguments
 */
void print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
}

/**
 * print_string - Prints a string
 * @args: A va_list of arguments
 */
void print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (str)
	{
		while (*str)
		{
			_putchar(*str);
			str++;
		}
	}
}

/**
 * print_percent - Prints a percent sign
 * @args: A va_list of arguments
 */
void print_percent(va_list args)
{
	(void)args;
	_putchar('%');
}

/**
 * print_int - Prints an integer
 * @args: A va_listof arguments
 */
void print_int(va_list args)
{
	int n = va_arg(args, int);
	char buffer[12];
	int i;

	i = 0;

	if (n < 0)
	{
		buffer[0] = '-';
		i++;
		n = -n;
	}

	do {
		buffer[i] = (n % 10) + '0';
		i++;
		n /= 10;
	} while (n > 0);
	buffer[i] = '\0';
	reverse_string(buffer);
	write(1, buffer, strlen(buffer));
}

/**
 * print_binary - Prints the binary representation of an unsigned integer.
 * @args: a va_list of arguments
 */
void print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[33];
	int i;

	i = 0;

	if (n == 0)
	{
		buffer[i++] = '0';
	}

	while (n > 0)
	{
		buffer[i++] = (n & 1) ? '1' : '0';
		n >>= 1;
	}
	buffer[i] = '\0';

	reverse_string(buffer);
	write(1, buffer, strlen(buffer));
}
