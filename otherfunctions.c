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

