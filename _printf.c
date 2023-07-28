#include "main.h"

/**
 * _printf - our own printf
 * @format: The format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int num_chars, i, j;
	va_list args;
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
			j = 0;

			while (print_functions[j].specifier != '\0')
			{
				if (format[i] == print_functions[j].specifier)
				{
					num_chars += print_functions[j].print_function(args);
					break;
				}
				j++;
			}
			if (print_functions[j].specifier == '\0')
			{
				_putchar('%');
				_putchar(format[i]);
				num_chars += 2;
			}
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

