#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * get_h - A pointer to a function
 * @s: A pointer to a string
 *
 * Return: A pointer to the correct function. or NULL if there is no match
 */
void (*get_h(const char *s))(unsigned int)
{
	int i = 0;

	conv_spec_h conv_specs[] = {
		{ "b", print_binary},
		{ "d", print_integer},
		{ "i", print_integer},
		{ "u", print_integer},
		{ "o", print_octal},
		{ "x", print_hexadecimal_x},
		{ "X", print_hexadecimal_X},
		{NULL, NULL}
	};

	while (conv_specs[i].conv_spec_ != NULL)
	{
		if (*s == *(conv_specs[i].conv_spec_))
		{
			return (conv_specs[i].h);
		}

		i++;
	}

	return (NULL);
}
