#include "main.h"

/**
 * print_pointer - Prints a pointer
 * @args: A va_list of arguments
 * Return: The number of characters printed
 */
int print_pointer(va_list args)
{
	void *ptr = va_arg(args, void*);
	int num_chars = 0;
	char *str = malloc(20);

	if (!str)
		return (-1);
	sprintf(str, "%p", ptr);
	while (*str)
	{
		_putchar(*str);
		num_chars++;
		str++;
	}
	free(str - num_chars);
	return (num_chars);
}
