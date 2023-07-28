#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


/**
 * struct sp - struct sp
 * @specifier: The specifier
 * @print_function: the print_function used
 */

typedef struct sp
{
	char specifier;
	int (*print_function)(va_list);
} print_map;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
void reverse_string(char *str);
int print_int(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);

#endif /* MAIN_H */
