#include "main.h"

/**
 * _printf - our own printf
 * @format: The format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int num_chars, i;
	va_list args;
	flags_t flags;
	print_map *print_functions = generate_print_map();

	if (format == NULL)
		return (-1);
	va_start(args, format);
	num_chars = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (0);
			flags = process_flags(format[i]);
			if (format[i] == '+' || format[i] == ' ' || format[i] == '#')
			{
				flags = process_flags(format[i]);
				i++;
			}
			num_chars += process_spec(format[i], args, flags, print_functions);

		}
		else
		{
			_putchar(format[i]);
			num_chars++;
		}
	}
	va_end(args);
	return (num_chars);
}
