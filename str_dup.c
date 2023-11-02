#include "shell.h"

/**
 * _strdup - Returns a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter
 * @s: String parameter
 *
 * Return: Pointer to a new string which is duplicate of str
 */

char *str_dup(char *s)
{
	char *new;
	int i, len;

	if (s == NULL)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	len++;
	new = malloc(sizeof(char) * len);
	if (new == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		new[i] = s[i];
	}
	return (new);
	free(new);
}
