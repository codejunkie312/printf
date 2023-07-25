#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct sp - struct sp
 * @specifier: The specifier
 * @print_function: the print_function used
 */

typedef struct sp
{
	char specifier;
	void (*print_function)(va_list);
} print_map;

extern print_map print_functions[];
int _printf(const char *format, ...);
int _putchar(char c);
void print_char(va_list args);
void print_string(va_list args);
void print_percent(va_list args);

#endif /* MAIN_H */
