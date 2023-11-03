#include "shell.h"

/**
 * std_error_printf - prints formatted output to stderr
 * @stream: File descriptor
 * @string: String to be read
 *
 * Return: No of chars read
 */

int std_error_printf(FILE *stream, const char *string)
{
	int count = 0;

	if (stream == NULL || string == NULL)
	{
		return (-1);
	}
	while (*string != '\0')
	{
		if (write(fileno(stream), string, 1) == -1)
		{
			return (-1);
		}
		count++;
		string++;
	}
	return (count);
}

/**
 * _printf - prints chars to stdout
 * @format: Format specifiers
 */
void _printf(const char *format, ...)
{
	va_list args;
	const char *prog_name, *arg, *str;

	va_start(args, format);
	prog_name = va_arg(args, const char*);
	arg = va_arg(args, const char*);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				str = *prog_name ? prog_name : "(null)";
				while (*str != '\0')
				{
					put_char(*str++);
				}
			}
			else if (*format == 's')
			{
				str = *arg ? arg : "(null)";
				while (*str != '\0')
				{
					put_char(*str++);
				}
			}
		}
		else
		{
			put_char(*format);
		}
		format++;
	}
	va_end(args);
}

