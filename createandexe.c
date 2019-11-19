#include "headersh.h"
/**
  * createandexesh - creat and execute the command given by user
  * @tokens: strings from stdin
  * @status: execute status
  * Return: nothing
  */
void createandexesh(char ***tokens, int *status)
{
	pid_t child_pid;
	int wait_status;

	(void) status;
	add_path(tokens);
	child_pid = fork();
	if (child_pid == -1)
	{
		printf("%s: 1: %s: not found", (*tokens)[0], (*tokens)[1]);
		return;
	}
	if (child_pid == 0)
	{
		if (execve((*tokens)[0], (*tokens), NULL) == -1)
		{
			perror("/hsh: 1: : not found");
			*status = 3;
		}
	}
	else
	{
		wait(&wait_status);
	}
}
