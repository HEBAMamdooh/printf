#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _print_cases - prints a single argument based on the given specifier.
 * @format: the string.
 * @args: the va_list of arguments.
 *
 * Return: the number of characters printed
 */
int _print_cases(const char *format, va_list args)
{
	int (*print_function)(char, const char *, long int, unsigned long int);
	int num_characters = 0;
	long int n = 0;
	unsigned long int m = 0;
	char *s = NULL, c = 'o';

	print_function = get_f(format);
	if (print_function == NULL)
	{
		num_characters += _putchar('%');
		if (*(format + 1) == ' ')
			format++;
		else
			num_characters += _putchar(*format);
	}
	else if (*format == 'c')
		n = print_function(va_arg(args, int), s, n, m);
	else if (*format == 's')
		n = print_function(c, va_arg(args, char *), n, m);
	else if (*format == '%')
		n = print_function('%', s, n, m);
	else if (*format == 'd' || *format == 'i' || *format == 'b' || *format == 'u'
		|| *format == 'o' || *format == 'x' || *format == 'X')
		n = print_function(*format, s, (long int)va_arg(args, int), m);
	else
		return (-1);
	if (n == -1)
		return (-1);
	num_characters += n;
	return (num_characters);
}

/**
 * _printf - produce output according to a format
 * @format: A character string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int num_characters = 0;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format != '%')
			num_characters += _putchar(*format);
		else if (*(format + 1) != '\0')
		{
			num_characters += _print_cases(++format, args);
		}
		else
			return (-1);
		format++;
	}
	va_end(args);
	return (num_characters);
}
