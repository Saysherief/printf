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
					putchar(va_arg(values, int));
					nchars++;
					break;
				case 's':
					nchars += print_string(va_arg(values, char *));
					break;
				case '%':
					putchar('%');
					nchars++;
					break;
				default:
					putchar(format[i - 1]);
					putchar(format[i]);
					nchars += 2;
					break;
			}
		}
		else
		{
			putchar(format[i]);
			nchars++;
		}
		i++;
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
