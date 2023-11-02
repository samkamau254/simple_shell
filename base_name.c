#include "shell.h"

/**
 * base_name - prints the name of file from a path
 * @path: Path to find filename
 *
 * Return: The filename in the path
 */

char *base_name(char *path)
{
	char *filename = path + strlength(path) - 1;

	while (filename > path && *filename != '\\' && *filename != '/')
	{
		filename--;
	}
	if (*filename == '\\' || *filename == '/')
		filename++;
	return (filename);
}
