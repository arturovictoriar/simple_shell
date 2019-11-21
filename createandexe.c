#include "headersh.h"

void free_tok(char ***tokens)
{
	free((*tokens)[0]);
}
/**
  * createandexesh - creat and execute the command given by user
  * @tokens: strings from stdin
  * @status: execute status
  * Return: nothing
  */
void createandexesh(char ***tokens, int *status, char **en, path_node *li_pa)
{
	pid_t child_pid;
	int wait_status, statu;

	statu = add_path(tokens, li_pa);
	child_pid = fork();
	if (child_pid == -1)
	{
		printf("%s: 1: %s: not found", (*tokens)[0], (*tokens)[1]);
		return;
	}
	if (child_pid == 0)
	{
		if (execve((*tokens)[0], (*tokens), en) == -1)
		{
			if (statu == 1)
				free_tok(tokens);

			perror("/hsh: 1: : not found");
			*status = 3;
			return;
		}
		if (statu == 1)
			free_tok(tokens);
	}
	else
	{
		wait(&wait_status);
		if (statu == 1)
			free_tok(tokens);
	}
}
