#include "shell.h"

/**
 * create_shell_data - initialize the shell data
 * @env: Environment variables
 *
 * Return: Shell structure
 */

shdata_t *create_shell_data(char **env)
{
	shdata_t *_shell_data = malloc(sizeof(shdata_t));

	if (_shell_data == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	_shell_data->user_input = NULL;
	_shell_data->interactive_mode = isatty(STDIN_FILENO);
	_shell_data->line_number = 0;
	_shell_data->command = NULL;
	_shell_data->cmd_path = NULL;
	_shell_data->env = env;
	return (_shell_data);
}

/**
 * shdata_free - frees the user input
 * @shell_data: Shell structure
 */
void shdata_free(shdata_t *shell_data)
{
	free_p((void **)&shell_data->user_input);
	free_p((void **)&shell_data->command);
	free(shell_data);
}

/**
 * tokeni_ze - tokenizes the user input
 * @shell_data: The data of the structure
 * @prev_cmd: Old command
 */

void tokeni_ze(shdata_t *shell_data, unsigned int *prev_cmd)
{
	char *input_cpy, *token;
	int i = 0, argc = 0;
	unsigned int new_cmd;
	char **cmd;

	input_cpy = str_dup(shell_data->user_input);
	if (input_cpy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	token = strtok(input_cpy, " \t\n");
	while (token != NULL)
	{
		argc++;
		token = strtok(NULL, " \t\n");
	}
	new_cmd = (argc + 1) * (sizeof(char *));
	cmd = re_alloc(shell_data->command, *prev_cmd, new_cmd);
	if (cmd == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	shell_data->command = cmd;
	*prev_cmd = new_cmd;
	token = strtok(shell_data->user_input, " \t\n");
	while (token)
	{
		shell_data->command[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	shell_data->command[i] = NULL;
	free(input_cpy);
}

/**
 * simple_shell - simple UNIX command interpretor
 * @input: Input file to be read
 * @name_of_prog: Program name to be printed on error
 * @env: Environment variables
 *
 * Return: 1 if success and NULL otherwise
 */

int simple_shell(char *name_of_prog, FILE *input, char **env)
{
	unsigned int prev_cmd_size = 0;
	shdata_t *shell_data;
	char prompt[] = "$ ";
	size_t len = 0;
	int value = 0;

	shell_data = create_shell_data(env);
	if (shell_data == NULL)
	{
		perror("shell data");
		return (-1);
	}
	while (1)
	{
		shell_data->line_number++;
		if (shell_data->interactive_mode)
		{
			write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
		}
		errno = 0;
		if (getline(&shell_data->user_input, &len, input) == -1)
		{
			if (errno == 0 || (errno == ENOTTY && !shell_data->interactive_mode))
				break;
			perror("getline");
			continue;
		}
		tokeni_ze(shell_data, &prev_cmd_size);
		if (shell_data->command == NULL || shell_data->command[0] == NULL)
			continue;
		value = execute_check(shell_data, name_of_prog);
	}
	shdata_free(shell_data);
	return (value);
}

/**
 * main - runs the shell program
 * @argc: Number of arguments
 * @argv: Pointer to a string of arguments
 * @env: Environment variables
 *
 * Return: Always 0(success)
 */

int main(int argc, char *argv[], char **env)
{
	FILE *input_file;
	char *name_of_prog = base_name(argv[0]);
	int value = 0;

	if (argc == 1)
	{
		value = simple_shell(name_of_prog, stdin, env);
	}
	else if (argc == 2)
	{
		input_file = fopen(argv[1], "r");
		if (input_file == NULL)
		{
			perror("fopen");
			exit(EXIT_FAILURE);
		}
		value = simple_shell(name_of_prog, input_file, env);
		fclose(input_file);
	}
	else
	{
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	return (value);
}

