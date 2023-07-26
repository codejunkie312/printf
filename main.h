#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1

/**
 * struct sp - struct sp
 * @specifier: The specifier
 * @print_function: the print_function used
 */

typedef struct sp
{
	char spc;
	int (*pfn)(va_list, char[], int, int, int, int);
} print_map;

int _printf(const char *format, ...);
int print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
int print_char(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_int(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list args, char buffer[],
	int flags, int width, int precision, int size)

#endif /* MAIN_H */
