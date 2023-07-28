#include "main.h"

/**
 * print_unsigned - prints an unsigned int
 * @args: a va_list arguments
 * Return: the number of characters printed
 */
int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert(num, 10);
	int i;

	i = 0;

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
 * print_octal - print an octal number
 * @args: a va_list argument
 * Return: The number of characters printed
 */
int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert(num, 8);
	int i;

	i = 0;
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
 * print_hex - prints a number in hex
 * @args: a va_list argument
 * Return: The number of characters printed
 */
int print_hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert(num, 16);
	int i;

	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		_putchar(tolower(str[i]));
		i++;
	}
	free(str);
	return (i);
}

/**
 * print_HEX - prints Hex numbers in uppercase
 * @args: a va_list argument
 * Return: The number of characters printed
 */
int print_HEX(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert(num, 16);
	int i;

	i = 0;

	if (str == NULL)
		return (-1);

	while (str[i] != '\0')
	{
		_putchar(toupper(str[i]));
		i++;
	}

	free(str);
	return (i);
}
