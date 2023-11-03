#include "shell.h"

/**
 * exitt - execute exit builtin command
 * @shell_data: Shell's data structure
 */
void exitt(shdata_t *shell_data)
{
	if (str_compare(shell_data->command[0], "exit") == 0)
	{
		shdata_free(shell_data);
		exit(EXIT_SUCCESS);
	}
}
/**
 * _env_ron - executes env builtin command
 * @shell_data: Shell's data structure
 */
void _env_ron(shdata_t *shell_data)
{
	char **env;
	int i;
	size_t len;

	env = shell_data->env;
	if (!env)
		return;
	if (str_compare(shell_data->command[0], "env") == 0)
	{
		for (i = 0; env[i] != NULL; i++)
		{
			len = strlength(env[i]);
			write(STDOUT_FILENO, env[i], len);
			write(STDOUT_FILENO, "\n", 1);
		}
	}
}
