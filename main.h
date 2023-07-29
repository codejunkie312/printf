#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/**
 * struct flags - struct flags
 * @plus: plus flag
 * @space: space flag
 * @hash: hash flag
 */

typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct sp - struct sp
 * @specifier: The specifier
 * @print_function: the print_function used
 */

typedef struct sp
{
	char specifier;
	int (*print_function)(va_list, flags_t);
} print_map;

int _printf(const char *format, ...);
int _putchar(char c);
char *convert(unsigned int num, int base);
int print_char(va_list args, flags_t flags);
int print_string(va_list args, flags_t flags);
int print_percent(va_list args, flags_t flags);
void reverse_string(char *str);
print_map *generate_print_map(void);
int print_int(va_list args, flags_t flags);
int print_binary(va_list args, flags_t flags);
int print_unsigned(va_list args, flags_t flags);
int print_octal(va_list args, flags_t flags);
int print_hex(va_list args, flags_t flags);
int print_HEX(va_list args, flags_t flags);
int print_string_non_printable(va_list args, flags_t flags);
int print_pointer(va_list args, flags_t flags);
flags_t process_flags(const char format);
int process_spec(const char fo, va_list args, flags_t flags, print_map *p_f);

#endif /* MAIN_H */
