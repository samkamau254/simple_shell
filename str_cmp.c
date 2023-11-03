#include "shell.h"
#include <stddef.h>

/**
 * str_compare - compares 2 strings
 * @str1: First string to be compared
 * @str2: Second string
 *
 * Return: Integer value that describes the relationship
 */

int str_compare(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (str1[i] - str2[i]);
}
