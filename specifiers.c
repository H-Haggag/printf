#include "main.h"

/**
 * get_specifier - finds format function
 * @s: format string
 *
 * Return: bytes
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format function
 * @s: format string
 * @ap: argument pointer
 * @params: parameters structure
 *
 * Return: bytes
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
	{
		return (f(ap, params));
	}
	return (0);
}

/**
 * get_flag - finds flag function
 * @s: format string
 * @params: parameters structure
 *
 * Return: int
 */
int get_flag(char *s, params_t *params)
{
	int d = 0;

	switch (*s)
	{
		case '+':
			d = params->plusFlag = 1;
			break;
		case ' ':
			d = params->spaceFlag = 1;
			break;
		case '#':
			d = params->hashtagFlag = 1;
			break;
		case '-':
			d = params->minusFlag = 1;
			break;
		case '0':
			d = params->zeroFlag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if modifier was valid
 */
int get_modifier(char *s, params_t *params)
{
	int b = 0;

	switch (*s)
	{
	case 'h':
		b = params->hModifier = 1;
		break;
	case 'l':
		b = params->lModifier = 1;
		break;
	}
	return (b);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *s, params_t *params, va_list ap)
{
	int a = 0;

	if (*s == '*')
	{
		a = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			a = a * 10 + (*s++ - '0');
	}
	params->width = a;
	return (s);
}
