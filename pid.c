#include "shell.h"

/**
 * execute_check - executes the executables
 * @shell_data: Data structure for shell
 * @program_name: Program name
 *
 * Return: 1 if Success and NULL otherwise
 */

int execute_check(shdata *shell_data, char *program_name);
{
	char *command_path = NULL, *path = NULL;
	int flag = 0, value = 0;

	if (built_in(shell_data->command[0]))
	{
		_env_ron(shell_data);
		exitt(shell_data);
		return (0);
	}
	if (str_chr(shell_data->command[0], '/') == NULL)
	{
		executable(shell_data, &command_path, &flag);
		path = flag ? command_path : NULL;
	}
	else
	{
		path = shell_data->command[0];
	}
	if (access(path, F_OK) != 0 || path == NULL)
	{
		print_f("%s: 1: %s: command not found\n", program_name,
				shell_data->command[0]);
		free_p((void **)&command_path);
		return (-1);
	}
	value = c_pid(shell_data, path);
	free_p((void **)&command_path);
	return (value);
}

/**
 * c_pid - creates a child process and runs execve
 * @shell_data: The shell structure
 * @path: Command path
 *
 * Return: 1 if success and NULL otherwise
 */

int c_pid(shdata_t *shell_data, char *path)
{
	pid_t c_pid;
	int status;

	c_pid = fork();
	if (c_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (c_pid == 0)
	{
		execve(path, shell_data->command, shell_data->_env_ron);
		perror(path);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
		else
		{
			return (-1);
		}
	}
}
