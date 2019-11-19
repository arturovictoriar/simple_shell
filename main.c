#include "headersh.h"

/**
  * set_all - set the given parameters to zero
  * @buffer: store the data get it
  * @tokens: store the string user wrote
  * @status: execute status
  * Return: nothing
  */

void set_all(char **buffer, char ***tokens, int *status)
{
	*status = 0;
	*buffer = NULL;
	*tokens = NULL;
}

/**
  * free_all - free the given parameters to zero
  * @buffer: store the data get it
  * @tokens: store the string user wrote
  * Return: nothing
  */

void free_all(char **buffer, char ***tokens)
{
	free(*buffer);
	free(*tokens);
}

/**
  * main - free the given parameters to zero
  * Return: nothing
  */

int main(void)
{
	char *buffer, **tokens;
	int len = 0, status;

	(void) env;
	do {
		/*Set all parameter in zero*/
		set_all(&buffer, &tokens, &status);
		/*Interactive shell prompt*/
		if (isatty(STDIN_FILENO))
			write(1, "($)", 4);
		/*READ section*/
		readsh(&buffer, &len, &status);
		/*Breaks cases*/
		if (status == 1 || status == 2)
			free(buffer);
		if (status == 1)
			continue;
		if (status == 2)
			return (1);
		/*Parse section*/
		parsesh(&buffer, &len, &tokens, &status);
		/*Create/Execute Section*/
		createandexesh(&tokens, &status);
		/*End of program*/
		free_all(&buffer, &tokens);
		/*Breaks cases*/
		if (status == 3)
			return (1);
	} while (isatty(STDIN_FILENO));
	return (1);
}
