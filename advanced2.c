#include "main.h"

/**
 * print_pointer - Prints a pointer
 * @args: A va_list of arguments
 * Return: The number of characters printed
 */
int print_pointer(va_list args)
{
	void *ptr = va_arg(args, void*);
	unsigned long int value = (unsigned long int) ptr;
	char *str;
	int count, i;

	count = 0;
	if (ptr == 0)
	{
		_putchar('(');
		_putchar('n');
		_putchar('i');
		_putchar('l');
		_putchar(')');
		return (5);
	}

	str = convert(value, 16);
	_putchar('0');
	_putchar('x');

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
		count++;
	}

	return (count + 2);
}
