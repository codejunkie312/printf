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
	print_map print_functions[] = {
	{'c', print_char},
	{'s', print_string},
	{'%', print_percent},
	{'i', print_int},
	{'d', print_int},
	{'b', print_binary},
	{'\0', NULL}
	};

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
					print_functions[j].print_function(args);
					break;
				}
				j++;
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

