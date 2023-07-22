#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _strlen - Return the length of a string
 * @s: The string whose length will be returned
 *
 * Return: The length of the string s.
 */
int _strlen(char *s)
{
	int length = 0;

	while (*(s + length) != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * _printf - produce output according to a format
 * @format: A character string
 *
 * The function Write to stdout, the standard output stream
 * The format string is composed of zero or more directives
 *
 * Return: The number of characters printed (excluding
 * the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, num_characters = 0;
	char *s;
	char c;

	va_start(args, format);
	i = 0;
	if (format != NULL)
	{
		while (*(format + i) != '\0')
		{
			if (*(format + i) != '%')
			{
				num_characters += write(1, format + i, 1);
			}
			else
			{
				if (*(format + i + 1) != '\0' && *(format + i + 1) == 'c')
				{
					c = va_arg(args, int);
					num_characters += write(1, &c, 1);
					i++;
				}
				else if (*(format + i + 1) != '\0' && *(format + i + 1) == 's')
				{
					s = va_arg(args, char *);
					num_characters += write(1, s, _strlen(s));
					i++;
				}
				else if (*(format + i + 1) != '\0' && *(format + i + 1) == '%')
				{
					write(1, format + i + 1, 1);
					i++;
				}
			}

			i++;
		}
	}
	return (num_characters);
}
