#include "main.h"

/**
 * number_digits_binary - Return the number of digits
 * @n: The input number
 *
 * Return: The number of digits.
 */
int number_digits_binary(unsigned int n)
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
int number_digits(unsigned int n)
{
	if (n / 10 == 0 && n % 10 == 0)
		return (0);

	return (1 + number_digits(n / 10));
}

/**
 * number_digits_octal - Return the number of digits
 * @n: The input integer
 *
 * Return: The number of digits.
 */
int number_digits_octal(unsigned int n)
{
	if (n / 8 == 0 && n % 8 == 0)
		return (0);

	return (1 + number_digits_octal(n / 8));
}

/**
 * number_digits_hexadecimal_x - Return the number of digits
 * @n: The input number
 *
 * Return: The number of digits.
 */
int number_digits_hexadecimal_x(unsigned int n)
{
	if (n / 16 == 0 && n % 16 == 0)
		return (0);

	return (1 + number_digits_hexadecimal_x(n / 16));
}
