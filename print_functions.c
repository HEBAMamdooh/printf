#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _print_char - Handle the conversion specifer c
 * @c: A character
 * @s: A pointer to a string
 * @n: An integer
 * @m: An unsigned integer
 *
 * Return: 1 or -1 if it fails.
 */
int _print_char(__attribute__((unused)) char c,
__attribute__((unused)) const char *s, __attribute__((unused)) long int n,
__attribute__((unused)) unsigned long int m)
{
	return (_putchar(c));
}
/**
 * _print_string - Handle the conversion specifer s
 * @c: A character
 * @s: A pointer to a string
 * @n: An integer
 * @m: An unsigned integer
 *
 * Return: The length of the string or -1 if it fails.
 */
int _print_string(__attribute__((unused)) char c,
__attribute__((unused)) const char *s, __attribute__((unused)) long int n,
__attribute__((unused)) unsigned long int m)
{
	return (_puts(s));
}
/**
 * _print_int - handle the conversion specifiers related to numbers
 * @c: A character
 * @s: A pointer to a string
 * @n: An integer
 * @m: An unsigned integer
 *
 * Return: The number of bytes printed or - 1 if it fails.
 */
int _print_int(__attribute__((unused)) char c,
__attribute__((unused)) const char *s, __attribute__((unused)) long int n,
__attribute__((unused)) unsigned long int m)
{
	int l;
	unsigned long int k = -n;

	if (n == 0)
	{
		_putchar('0');
		l = 1;
	}
	if (c == 'b' && n > 0)
	{
		print_binary(n);
		l = number_digits_binary(n);
	}
	else if (c == 'o' && n > 0)
	{
		print_octal(n);
		l = number_digits_octal(n);
	}
	else if (c == 'x' && n > 0)
	{
		print_hexadecimal_x(n);
		l = number_digits_hexadecimal_x(n);
	}
	else if (c == 'X' && n > 0)
	{
		print_hexadecimal_X(n);
		l = number_digits_hexadecimal_x(n);
	}
	if ((c == 'd' || c == 'i' || c == 'u') &&  n > 0)
	{
		print_integer(n);
		l = number_digits(n);
	}
	else if ((c == 'd' || c == 'i') && n < 0)
	{
		_putchar('-');
		print_integer(k);
		l = number_digits(k) + 1;
	}
	return (l);
}
