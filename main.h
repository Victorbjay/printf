#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

int _write_char(char c);
int _write_string(char *str);
int _printf(const char *format, ...);
int _print_percent(void);
int _print_undefined(char c);
int _putchar(char c);
void print_binary(va_list args);

#endif /* MAIN_H */

