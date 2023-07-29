#include "main.h"

/**
 * reverse_string - Reverses a string in place
 * @str: The string to reverse
 */
void reverse_string(char *str)
{
	int start, end;
	char temp;

	start = 0;
	end = strlen(str) - 1;
	if (str[start] == '-')
		start++;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

/**
 * print_map - maps specifiers to their function
 * Return: a print_map type
 */
print_map *generate_print_map(void)
{
	static print_map print_functions[] = {
	{'c', print_char}, {'s', print_string}, {'%', print_percent},
	{'i', print_int}, {'d', print_int}, {'b', print_binary},
	{'u', print_unsigned}, {'o', print_octal}, {'x', print_hex},
	{'X', print_HEX}, {'S', print_string_non_printable},
	{'p', print_pointer},
	{'\0', NULL}
	};

	return (print_functions);
}

/**
 * convert - converts a number into a specified base from 2 to 16
 * @num: number to convert
 * @base: base to convert to
 * Return: poiner to a string
 */
char *convert(unsigned int num, int base)
{
	char *ptr = malloc(50 * sizeof(char));
	char *end;

	if (ptr == NULL)
		return (NULL);
	end = ptr + 49;
	*end = '\0';

	do {
		*--end = "0123456789abcdef"[num % base];
		num /= base;
	} while (num != 0);

	return (end);
}

/**
 * process_flags - returns which flag is present
 * @format: a char
 * Return: a flag_t value composed of three see struct in main.h
 */
flags_t process_flags(const char format)
{
	flags_t flags = {0, 0, 0};

	if (format == '+')
		flags.plus = 1;
	else if (format == ' ')
		flags.space = 1;
	else if (format == '#')
		flags.hash = 1;

	return (flags);
}

/**
 * process_spec - sperated specifier logic
 * @fo: a pointer to a string
 * @args: a va8list of arguments
 * @flags: flags
 * @p_f: map of print functions
 * Return: number of characters printed
 */
int process_spec(const char fo, va_list args, flags_t flags, print_map *p_f)
{
	int num_chars;
	int j;

	num_chars = 0;
	j = 0;

	while (p_f[j].specifier != '\0')
	{
		if (fo == p_f[j].specifier)
		{
			num_chars += p_f[j].print_function(args, flags);
			return (num_chars);
		}
		j++;
	}
	if (p_f[j].specifier == '\0' && fo != '+' && fo != ' ' && fo != '#')
	{
		_putchar('%');
		_putchar(fo);
		num_chars += 2;
	}
	else
	{
		fprintf(stderr, "Error: unrecognized format specifier '%c'\n", fo);
		return (-1);
	}
	return (num_chars);
}
