#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Arguments to be formatted
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* Move past '%' */

			switch (*format)
			{
			case 'd':
			case 'i':
				count += printf("%d", va_arg(args, int));
				break;
			case 'o':
				count += printf("%o", va_arg(args, unsigned int));
				break;
			default:
				putchar('%'); /* Print the '%' character */
				count++;
				if (*format != '\0')
				{
					putchar(*format); /* Print the unknown specifier */
					count++;
				}
				break;
			}
		}
		else
		{
			putchar(*format); /* Print non-format characters */
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

