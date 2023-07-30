#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct conv_spec - Struct conv_spec
 * @conv_spec: The conversion specifier
 * @f: The function associated
 */
typedef struct conv_spec
{
	char *conv_spec;
	int (*f)(char c, const char *s, int n, unsigned int m);
} conv_spec_t;

/**
 * struct conv_spec_ - Struct conv spec
 * @conv_spec_: The conversion specifier
 * @h: The function associated
 */
typedef struct conv_spec_
{
	char *conv_spec_;
	void (*h)(unsigned int n);
} conv_spec_h;

int _putchar(char c);
int _puts(const char *s);
int _printf(const char *format, ...);
int _print_cases(const char *format, va_list args);

int _print_char(char c, const char *s, int n, unsigned int m);
int _print_string(char c, const char *s, int n, unsigned int m);
int _print_int(char c, const char *s, int n, unsigned int m);
int (*get_f(const char *s))(char, const char *, int, unsigned int);
void (*get_h(const char *s))(unsigned int n);

void print_binary(unsigned int n);
void print_integer(unsigned int n);
void print_octal(unsigned int n);
void print_hexadecimal_x(unsigned int n);
void print_hexadecimal_X(unsigned int n);
int number_digits_binary(int n);
int number_digits(int n);
int number_digits_octal(int n);
int number_digits_hexadecimal_x(int n);

#endif /* MAIN_H */
