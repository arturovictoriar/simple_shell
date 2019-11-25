#include "headersh.h"

/**
 * free_tok - frees the @tokens string
 * @tokens: string containing the parsed input line
 * Return: nothing
 */
void free_tok(char ***tokens)
{
	free((*tokens)[0]);
}

/**
  * createandexesh - creat and execute the command given by user
  * @tokens: strings from stdin
  * @cc: is the counter of commans executes by user
  * @en: list containing the end parameter for execve syscall
  * @av: list containing the arguments given by user
  * Return: the process status
  */
int createandexesh(char ***tokens, int *cc, char **en, char **av)
{
	pid_t child_pid;
	int wait_status = 0, statu = 0;

	statu = built_ins_sh(tokens, en, *tokens);
	if (statu != 0)
		return (0);

	statu = add_path(tokens, en);
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve((*tokens)[0], (*tokens), en) == -1)
		{
			if (statu == 1)
				free_tok(tokens);
			dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", av[0], *cc, (*tokens)[0]);
			return (127);
		}
	}
	else
		wait(&wait_status);

	if (statu == 1)
		free_tok(tokens);

	return (0);
}
