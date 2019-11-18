#include "headersh.h"

void createandexesh(char ***tokens)
{
	pid_t child_pid;
	int wait_status;
	
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		execve((*tokens)[0], (*tokens), NULL);
	}
	else
	{
		wait(&wait_status);
	}
}
