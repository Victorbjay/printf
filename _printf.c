#include "main.h"
#include <unistd.h>
#include <stddef.h>

/**
 * _write_char - Writes a character to standard output.
 * @c: The character to write.
 *
 * Return: The number of characters written.
 */
int _write_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * _write_string - Writes a string to standard output.
 * @str: The string to write.
 *
 * Return: The number of characters written.
 */
int _write_string(char *str)
{
	int count = 0;

	while (*str)
	{
		count += _write_char(*str);
		str++;
	}

	return (count);
}

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
	char c;
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
					c = (char)va_arg(args, int);
					count += _write_char(c);
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

