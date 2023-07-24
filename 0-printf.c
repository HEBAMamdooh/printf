#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produce output according to a format
 * @format: A character string
 *
 * Return: The number of characters printed (excluding
 * the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	int (*print_function)(char, const char *, int);
	int num_characters = 0, n = 0;
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
				print_function = get_print_function(++format);
				if (*format == 'c')
					num_characters += print_function(va_arg(args, int), s, n);
				else if (*format == 's')
					num_characters += print_function(c, va_arg(args, char *), n);
				else if (*format == '%')
					num_characters += print_function('%', s, n);
				else if (*format == 'b')
				{
					n = print_function(*format, s, va_arg(args, int));
					if (n > 0)
						num_characters += n;
				}
				else
					return (-1);
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
