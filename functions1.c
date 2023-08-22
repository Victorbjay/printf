#include <stdarg.h>
#include <stdio.h>

/**
 * print_binary - Print the binary representation of an unsigned integer.
 * @args: The va_list containing the unsigned int argument.
 */
void print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int mask = 1;
	int printed = 0;

	mask <<= 31;
	if (num == 0)
	{
		_putchar('0');
		return;
	}

	while (mask)
	{
		if (num & mask)
		{
			_putchar('1');
			printed++;
		}
		else if (printed)
			_putchar('0');
		mask >>= 1;
	}
}

