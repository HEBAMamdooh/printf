#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * get_print_function - A pointer to a function
 * @s: A pointer to a string
 *
 * Return: A pointer to the correct function. or NULL if there is no match
 */
int (*get_print_function(const char *s))(char, const char*, long)
{
	int i = 0;

	conv_spec_t conv_specs[] = {
		{ "c", _print_char},
		{ "s", _print_string},
		{ "%", _print_char},
		{ "b", _print_int},
		{ "d", _print_int},
		{ "i", _print_int},
		{ "u", _print_int},
		{NULL, NULL}
	};

	while (conv_specs[i].conv_spec != NULL)
	{
		if (*s == *(conv_specs[i].conv_spec))
		{
			return (conv_specs[i].f);
		}

		i++;
	}

	return (NULL);
}
