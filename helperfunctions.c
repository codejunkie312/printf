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

void print_percent(va_list args)
{
	(void)args;
	_putchar('%');
}

print_map print_functions[] = {
	{'c', print_char},
	{'s', print_string},
	{'%', print_percent},
	{'\0', NULL}
};
