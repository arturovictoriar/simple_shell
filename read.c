#include "headersh.h"

/**
  * num_tokens - execute a simple shell
  * @buffer: argument vector (unused)
  * @read: external variable environment parsed by lines
  * Return: number of nodes
  */

int num_tokens(char **buffer, ssize_t read)
{
	const char delim[] = " \n";
	char *token, *copybuffer = NULL;
	int i;

	copybuffer = malloc(sizeof(char) * read + 1);
	if (copybuffer == NULL)
	{
		printf("Error puto 2\n");
		return (0);
	}
	for (i = 0; buffer[0][i] != '\0'; i++)
		copybuffer[i] = buffer[0][i];
	copybuffer[i] = buffer[0][i];
	token = strtok(copybuffer, delim);
	for (i = 0; token != NULL; i++)
		token = strtok(NULL, delim);
	free(copybuffer);
	return (i);
}

/**
  * readsh - read what user wrote
  * @buffer: store the data get it
  * @len: lenght of the tokens
  * Return: nothing
  */

int readsh(char **buffer, int *len)
{
	ssize_t read = 0;
	size_t sizebuf = 0;

	/* READ section*/
	read = getline(buffer, &sizebuf, stdin);
	if (read == -1 || (*buffer)[read - 1] != '\n')
	{
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
		return (2);
	}
	/*New line*/
	if (buffer[0][0] == '\n')
		return (1);
	*len = num_tokens(buffer, read);
	return (0);
}
