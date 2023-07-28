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
	free(ptr);
	return (end);
}
