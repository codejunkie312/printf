#include "main.h"

/**
 * print_char - prints a character
 * @args: A va_list of arguments
 * Return: The number of characters printed
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * print_string - Prints a string
 * @args: A va_list of arguments
 * Return: the number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char*);
	int i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * print_percent - Prints a percent sign
 * @args: A va_list of arguments
 * Return: The number of characters printed
 */
int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}

/**
 * print_int - Prints an integer
 * @args: A va_list of arguments
 * Return: The number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	unsigned int un;
	char *str;
	int count;

	count = 0;
	if (n < 0)
	{
		_putchar('-');
		un = -n;
		count++;
	} else
		un = n;
	str = convert(un, 10);
	if (str == NULL)
		return (-1);
	while (*str != '\0')
	{
		_putchar(*str);
		count++;
		str++;
	}
	return (count);
}

/**
 * print_binary - Prints the binary representation of an unsigned integer.
 * @args: a va_list of arguments
 * Return: The number of characters printed
 */
int print_binary(va_list args)
{
	unsigned long int num = va_arg(args, unsigned long int);
	int is_negative, i;
	char *str;

	is_negative = 0;

	if ((long int) num < 0)
	{
		is_negative = 1;
		num = ~num + 1;
	}
	str = convert(num, 2);
	i = 0;
	if (str == NULL)
		return (-1);

	if (is_negative)
		_putchar('-');
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

