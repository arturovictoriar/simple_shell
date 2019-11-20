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

void free_list(path_node *list_path)
{
	path_node *savepoin;

	if (list_path != NULL)
	{
		while (list_path != NULL)
		{
			savepoin = list_path->next;
			free(list_path);
			list_path = savepoin;
		}
	}
}

/**
  * main - free the given parameters to zero
  * Return: nothing
  */

int main(int ac, char **av, char **en)
{
	char *buffer, **tokens;
	int len = 0, status;
	path_node *list_path;

	(void) ac;
	(void) av;
	get_path(&list_path, en);
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
		{
			free_list(list_path);
			return (1);
		}
		/*Parse section*/
		parsesh(&buffer, &len, &tokens, &status);
		/*Create/Execute Section*/
		createandexesh(&tokens, &status, en, list_path);
		/*End of program*/
		free_all(&buffer, &tokens);
		/*Breaks cases*/
		if (status == 3)
		{
			free_list(list_path);
			return (1);
		}
	} while (isatty(STDIN_FILENO));
	return (1);
}
