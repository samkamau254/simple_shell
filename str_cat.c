#include "shell.h"

/**
 * str_cat - concatenates two strings
 * @dest: initial string
 * @place: the string to be appended
 *
 * Return: Returns a pointer to the resulting string dest
 */

char *str_cat(char *dest, char *place)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (place[j] != '\0')
	{
		dest[i] = place[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

