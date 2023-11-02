#include "shell.h"

/**
 * strlength - gives the length of a string
 * @str: Input string
 *
 * Return: Length of the string
 */

int strlength(char *str)
{
	int length;

	length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}
