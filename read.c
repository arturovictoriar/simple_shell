#include "headersh.h"

/**
  * readsh - read what user wrote
  * @buffer: store the data get it
  * @len: lenght of the tokens
  * @status: execute status
  * Return: nothing
  */

void readsh(char **buffer, int *len, int *status)
{
	ssize_t read = 0;
	size_t sizebuf = 20;
	char *copybuffer = NULL, *token;
	const char delim[] = " ";
	int i;

	/* READ section*/
	read = getline(buffer, &sizebuf, stdin);
	if (read == -1)
	{
		printf("Error puto 1\n");
		*status = 2;
		return;
	}
	/*New line*/
	if (buffer[0][0] == '\n')
	{
		*status = 1;
		return;
	}
	/*copybuffer*/
	copybuffer = malloc(sizeof(char) * read);
	if (copybuffer == NULL)
	{
		printf("Error puto 2\n");
		return;
	}
	for (i = 0; buffer[0][i] != '\0'; i++)
		copybuffer[i] = buffer[0][i];
	i--;
	copybuffer[i] = '\0';
	buffer[0][i] = '\0';
	token = strtok(copybuffer, delim);
	for (i = 0; token != NULL; i++)
		token = strtok(NULL, delim);
	*len = i;
	free(copybuffer);
}
