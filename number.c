#include "main.h"

/**
 * number_digits_binary - Return the number of digits
 * @n: The input number
 *
 * Return: The number of digits.
 */
int number_digits_binary(int n)
{
	if (n / 2 == 0 && n % 2 == 0)
		return (0);

	return (1 + number_digits_binary(n / 2));
}

/**
 * print_binary - Handle the conversion specifier b
 * @n: The input unsigned int
 *
 * The function converts the unsigned argument to binary
 *
 * Return: The number of bytes printed.
 */
void print_binary(unsigned int n)
{
	if (n / 2 == 0 && n % 2 == 0)
		return;

	print_binary(n / 2);
	_putchar('0' + n % 2);
}
