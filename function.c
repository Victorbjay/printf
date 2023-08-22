#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _print_percent - Prints a '%' character to stdout.
 *
 * Return: The number of characters printed.
 */

int _print_percent(void)
{
	return (write(1, "%", 1));
}

/**
 * _print_undefined - Prints an undefined character to stdout.
 * @c: The character to print.
 *
 * Return: The number of characters printed.
 */
int _print_undefined(char c)
{
	return (write(1, &c, 1));
}

