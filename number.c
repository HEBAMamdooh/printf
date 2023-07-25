#include "main.h"

/**
 * number_digits_binary - Return the number of digits
 * @n: The input number
 *
 * Return: The number of digits.
 */
int number_digits_binary(long int n)
{
	if (n / 2 == 0 && n % 2 == 0)
		return (0);

	return (1 + number_digits_binary(n / 2));
}

/**
 * number_digits - Return the number of digits of a decimal
 * @n: The input number
 *
 * Return: The number of digits.
 */
int number_digits(long int n)
{
	if (n / 10 == 0 && n % 10 == 0)
		return (0);

	return (1 + number_digits(n / 10));
}

/**
 * print_binary - Handle the conversion specifier b
 * @n: The input unsigned int
 *
 * The function converts the unsigned argument to binary
 *
 * Return: void.
 */
void print_binary(unsigned long int n)
{
	if (n / 2 == 0 && n % 2 == 0)
		return;

	print_binary(n / 2);
	_putchar('0' + n % 2);
}

/**
 * print_integer - Handle the conversion specifiers d and i
 * @n: The input integer
 *
 * Return: void
 */
void print_integer(unsigned int n)
{
	if (n / 10 == 0 && n % 10 == 0)
		return;

	print_integer(n / 10);
	_putchar('0' + n % 10);
}

/**
 * print_unsigned_integer - Handle the conversion specifier u
 * @n: The input integer
 *
 * Return void.
 */
void print_unsigned_integer(unsigned long int n)
{
	print_integer(n);
}
