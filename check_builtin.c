#include "shell.h"

/**
 * built_in - checks if a command is builtin
 * @cmd: The command to be checked
 *
 * Return: True if command is built-in and false otherwise
 */

bool built_in(char *cmd)
{
	char *builtin[] = {"exit", "env"};
	unsigned long int i;

	for (i = 0; i < sizeof(builtin) / sizeof(builtin[0]); i++)
	{
		if (str_compare(cmd, builtin[i]) == 0)
		{
			return (true);
		}
	}
	return (false);
}
