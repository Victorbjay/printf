#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

int _write_char(char c);
int _write_string(char *str);
int _printf(const char *format, ...);

#endif /* MAIN_H */

