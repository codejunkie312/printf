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

