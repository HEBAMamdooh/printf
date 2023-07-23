#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef struct conv_spec
{
	char *conv_spec;
	int (*f)(char c, const char *s, int n);
} conv_spec_t;

int _putchar(char c);
int _puts(const char *s);
int _printf(const char *format, ...);
int _print_char(char c, const char *s, int n);
int _print_string(char c, const char *s, int n);
int (*get_print_function(const char *s))(char, const char *, int);

#endif /* MAIN_H */
