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
	char *str;
	int i;
	int num = va_arg(args, int);

	i = 0;
	str = convert(num, 10);
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	free(str);
	return (i);
}

/**
 * print_binary - Prints the binary representation of an unsigned integer.
 * @args: a va_list of arguments
 * Return: The number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert(num, 2);
	int i;

	i = 0;

	if (str == NULL)
		return (-1);

	while (str[i != '\0'])
	{
		_putchar(str[i]);
		i++;
	}
	free(str);
	return (i);
}

