#include "main.h"

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
void print_integer(unsigned long int n)
{
	if (n / 10 == 0 && n % 10 == 0)
		return;

	print_integer(n / 10);
	_putchar('0' + n % 10);
}

/**
 * print_octal - Handle the conversion specifer o
 * @n: The input integer
 *
 * Return: void
 */
void print_octal(unsigned long int n)
{
	if (n / 8 == 0 && n % 8 == 0)
		return;

	print_octal(n / 8);
	_putchar('0' + n % 8);
}

/**
 * print_hexadecimal_x - Handle the conversion specifier x
 * @n: The input integer
 *
 * Return: void
 */
void print_hexadecimal_x(unsigned long int n)
{
	if (n / 16 == 0 && n % 16 == 0)
		return;

	print_hexadecimal_x(n / 16);

	if (n % 16 == 10)
		_putchar('a');
	else if (n % 16 == 11)
		_putchar('b');
	else if (n % 16 == 12)
		_putchar('c');
	else if (n % 16 == 13)
		_putchar('d');
	else if (n % 16 == 14)
		_putchar('e');
	else if (n % 16 == 15)
		_putchar('f');
	else
		_putchar('0' + n % 16);
}

/**
 * print_hexadecimal_X - Handle the conversion specifier X
 * @n: The input integer
 *
 * Return: void
 */
void print_hexadecimal_X(unsigned long int n)
{
	if (n / 16 == 0 && n % 16 == 0)
		return;

	print_hexadecimal_X(n / 16);

	if (n % 16 == 10)
		_putchar('A');
	else if (n % 16 == 11)
		_putchar('B');
	else if (n % 16 == 12)
		_putchar('C');
	else if (n % 16 == 13)
		_putchar('D');
	else if (n % 16 == 14)
		_putchar('E');
	else if (n % 16 == 15)
		_putchar('F');
	else
		_putchar('0' + n % 16);
}
