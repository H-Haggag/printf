#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1


#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONV_LOWER	1
#define CONV_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unSign: flag if unsigned value
 *
 * @plusFlag: on if plusFlag
 * @spaceFlag: on if spaceFlag
 * @hashtagFlag: on if hashtagFlag
 * @zeroFlag: on if zeroFlag
 * @minusFlag: on if minusFlag
 *
 * @width: field widtt
 * @precision: field precision
 *
 * @hModifier: on if hModifier
 * @lModifier: on if lModifier
 *
 */
typedef struct parameters
{
	unsigned int unSign			: 1;

	unsigned int plusFlag		: 1;
	unsigned int spaceFlag		: 1;
	unsigned int hashtagFlag	: 1;
	unsigned int zeroFlag		: 1;
	unsigned int minusFlag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int hModifier		: 1;
	unsigned int lModifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

int _puts(char *str);
int _putchar(int c);

int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

void init_params(params_t *params, va_list ap);

char *get_precision(char *p, params_t *params, va_list ap);

int _printf(const char *format, ...);

#endif

