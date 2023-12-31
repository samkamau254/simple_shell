#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <libgen.h>
#include <stdbool.h>
#include <limits.h>
#include <dirent.h>
#include <stdarg.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1000


/**
 * struct shdata - the shell struct data
 * @user_input: What the user inputs
 * @interactive_mode: Checks if it's interactive mode
 * @line_number: Number of lines
 * @command: Command typed by user
 * @env: The environment variables
 * @cmd_path: Path to the executable
 */

typedef struct shdata
{
	char *user_input;
	int interactive_mode;
	unsigned int line_number;
	char **command;
	char **env;
	char *cmd_path;
} shdata_t;

int strlength(char *str);
int str_compare(char *str1, char *str2);
int simple_shell(char *program_name, FILE *input_f, char **env);
void exitt(shdata_t *shell_data);
void _env_ron(shdata_t *shell_data);
bool built_in(char *command);
char *str_chr(char *s, char c);
void executable(shdata_t *shell_data, char **full_path, int *flag);
int c_pid(shdata_t *shell_data, char *path);
char *str_dup(char *s);
char *base_name(char *path);
int std_error_printf(FILE *stream, const char *string);
int put_char(char c);
void print_f(const char *format, ...);
shdata_t *create_shell_data(char **env);
void shdata_free(shdata_t *shell_data);
void tokenize_it(shdata_t *shell_data, unsigned int *prev_cmd);
void free_p(void **ptr);
char *mem_cpy(char *dest, char *place, unsigned int k);
void *re_alloc(void *ptr, unsigned int prev, unsigned int n_size);
int execute_check(shdata_t *shell_data, char *program_name);
char *str_cpy(char *dest, char *src);
char *str_cat(char *dest, char *place);

#endif
