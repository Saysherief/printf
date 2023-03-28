#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: a string passed as an argument may include format specifiers
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list values;
	unsigned int nchars = 0, i = 0;

	if (format == NULL)
		return (-1);
	va_start(values, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					putchar(va_arg(values, int)), nchars++;
					break;
				case 's':
					nchars += print_string(va_arg(values, char *));
					break;
				case '%':
					putchar('%'), nchars++;
					break;
				case 'd': case'i':
					nchars += print_int(va_arg(values, int));
					break;
				default:
					putchar(format[i - 1]);
					putchar(format[i]), nchars += 2;
					break;
			}
		}
		else
		{
			putchar(format[i]), nchars++;
		} i++;
	}
	va_end(values);
	return (nchars);
}

/**
 * print_string - a function that prints a given string
 * @str: the string to be printed
 * Return: the number of characters printed
 */
int print_string(char *str)
{
	unsigned int nchars = 0, i = 0;

	if (str == NULL)
	{
		return (printf("(null)"));
	}
	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
		nchars++;
	}
	return (nchars);
}

/**
 * print_int- prints the number taken in the argument
 * @n: the integer to be printed
 * Return: the number of characters printed
 */
int print_int(int n)
{
	unsigned int dig, value, subs, nchars = 0;

	dig = 1;
	value = n;
	subs = n;
	if (n < 0)
	{
		putchar('-');
		value *= (-1);
		subs *= (-1);
		nchars++;
	}
	while (subs > 9)
	{
		subs /= 10;
		dig *= 10;
	}
	for (; dig >= 1; dig /= 10)
	{
		putchar(((value / dig) % 10) + '0');
		nchars++;
	}
	return (nchars);
}
