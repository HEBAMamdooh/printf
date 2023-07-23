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
		length++;
	return (length);
}

/**
 * _printf - produce output according to a format
 * @format: A character string
 *
 * Return: The number of characters printed (excluding
 * the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, num_characters = 0;
	char *s, c;

	va_start(args, format);
	if (format != NULL)
	{
		while (*(format + i) != '\0')
		{
			if (*(format + i) != '%')
				num_characters += write(1, format + i, 1);
			else
			{
				if (*(format + i + 1) != '\0' && *(format + i + 1) == 'c')
				{
					c = va_arg(args, int);
					num_characters += write(1, &c, 1);
				}
				else if (*(format + i + 1) != '\0' && *(format + i + 1) == 's')
				{
					s = va_arg(args, char *);
					if (s != NULL)
						num_characters += write(1, s, _strlen(s));
				}
				else if (*(format + i + 1) != '\0' && *(format + i + 1) == '%')
					num_characters += write(1, format + i + 1, 1);
				else
					return (-1);
				i++;

			}
			i++;
		}
	}
	else
		return (-1);
	return (num_characters);
}
