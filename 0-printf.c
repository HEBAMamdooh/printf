#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produce output according to a format
 * @format: A character string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int (*print_function)(char, const char *, long int, unsigned long int);
	int num_characters = 0, n = 0;
	unsigned int m = 0;
	char *s = NULL, c = 'o';
	va_list args;

	va_start(args, format);
	if (format != NULL)
	{
		while (*format != '\0')
		{
			if (*format != '%')
				num_characters += _putchar(*format);
			else if (*(format + 1) != '\0')
			{
				print_function = get_f(++format);
				if (*format == 'c')
					n = print_function(va_arg(args, int), s, n, m);
				else if (*format == 's')
					n = print_function(c, va_arg(args, char *), n, m);
				else if (*format == '%')
					n = print_function('%', s, n, m);
				else if (*format == 'd' || *format == 'i' || *format == 'b')
					n = print_function(*format, s, (long int)va_arg(args, int), m);
				else
					return (-1);
				if (n == -1)
					return (-1);
				num_characters += n;
			}
			else
				return (-1);
			format++;
		}
	}
	else
		return (-1);
	va_end(args);
	return (num_characters);
}
