#include "main.h"

/**
 * print_unsigned - prints an unsigned int
 * @args: a va_list arguments
 * @flags: flags
 * Return: the number of characters printed
 */
int print_unsigned(va_list args, flags_t flags)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert(num, 10);
	int i;

	UNUSED(flags);
	i = 0;

	if (str == NULL)
		return (-1);

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

/**
 * print_octal - print an octal number
 * @args: a va_list argument
 * @flags: flags
 * Return: The number of characters printed
 */
int print_octal(va_list args, flags_t flags)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert(num, 8);
	int i, num_chars;

	i = 0;
	num_chars = 0;
	if (str == NULL)
		return (-1);

	if (flags.hash)
	{
		_putchar('0');
		num_chars += 1;
	}

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (i + num_chars);
}

/**
 * print_hex - prints a number in hex
 * @args: a va_list argument
 * @flags: flags
 * Return: The number of characters printed
 */
int print_hex(va_list args, flags_t flags)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert(num, 16);
	int i, num_chars;

	num_chars = 0;
	i = 0;
	if (str == NULL)
		return (-1);
	if (flags.hash)
	{
		_putchar('0');
		_putchar('x');
		num_chars += 2;
	}
	while (str[i] != '\0')
	{
		_putchar(tolower(str[i]));
		i++;
	}
	return (i + num_chars);
}

/**
 * print_HEX - prints Hex numbers in uppercase
 * @args: a va_list argument
 * @flags: flags
 * Return: The number of characters printed
 */
int print_HEX(va_list args, flags_t flags)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert(num, 16);
	int i, num_chars;

	i = 0;
	num_chars = 0;
	if (str == NULL)
		return (-1);
	if (flags.hash)
	{
		_putchar('0');
		_putchar('x');
		num_chars += 2;
	}
	while (str[i] != '\0')
	{
		_putchar(toupper(str[i]));
		i++;
	}

	return (i + num_chars);
}

/**
 * print_string_non_printable - Prints a string. for a non-printable characters
 * (0 < ASCII value < 32 or >= 127), prints \x followed by the ASCII code value
 * in hexadecimal (upper case - always 2 characters)
 * @args: a va_list of arguments
 * @flags: flags
 * Return: The number of characters printed
 */
int print_string_non_printable(va_list args, flags_t flags)
{
	char *str = va_arg(args, char *);
	int i, count;
	char temp[5];
	unsigned char c;

	UNUSED(flags);
	i = 0;
	count = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i])
	{
		c = str[i];
		if ((c > 0 && c < 32) || c >= 127)
		{
			_putchar('\\');
			_putchar('x');
			sprintf(temp, "%02X", c);
			_putchar(temp[0]);
			_putchar(temp[1]);
			count += 4;
		}
		else
		{
			_putchar(c);
			count++;
		}
		i++;
	}
	return (count);
}

