#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *str;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				count += _write_char(va_arg(args, int));
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				count += _write_string(str);
				break;
			case '%':
				count += _write_char('%');
				break;
			case 'b':
				print_binary(va_arg(args, unsigned int), &count);
				break;
			default:
				count += _write_char('%') + _write_char(*format);
				break;
			}
		}
		else
		{
			count += _write_char(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}

