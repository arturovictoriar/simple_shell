#include "headersh.h"

/**
* set_all - set the given parameters to zero
* @buffer: store the data get it
* @tokens: store the string user wrote
* @stat: execute status
* Return: nothing
*/
void set_all(char **buffer, char ***tokens, int *stat)
{
	*stat = 0;
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
* free_list- frees the linked list containing the path directories
* @list_path: the linked list to be freed
* Return: nothing
*/
void free_list(path_node *list_path)
{
	path_node *savepoin;

	if (list_path != NULL)
	{
		while (list_path != NULL)
		{
			savepoin = list_path->next;
			if (savepoin == NULL)
				free(list_path->str);
			free(list_path);
			list_path = savepoin;
		}
	}
}
/**
* ctrlc- skkiped the ctrl signal
* @ctr_c: ctrl c signal
* Return: nothing
*/
void ctrlc(int ctr_c __attribute__((unused)))
{
	write(1, "\n($)", 5);
}
/**
* simple_sh - execute a simple shell
* @av: argument vector (unused)
* @en: external variable environment parsed by lines
* Return: nothing
*/
int simple_sh(char **av, char **en)
{
	char *buffer, **tokens;
	int len = 0, status = 0, stat = 0, cont_com = 0;

	signal(SIGINT, ctrlc);
	do {
		/*Count all iterations*/
		cont_com++;
		/*Set all parameter in zero*/
		set_all(&buffer, &tokens, &stat);
		/*Interactive shell prompt*/
		if (isatty(STDIN_FILENO))
			write(1, "($)", 4);
		/*READ section*/
		stat = readsh(&buffer, &len);
		/*Breaks cases*/
		if (stat == 1 || stat == 2)
			free(buffer);
		if (stat == 1)
			continue;
		if (stat == 2)
			return (status);
		/*Parse section*/
		parsesh(&buffer, &len, &tokens, &status);
		/*Create/Execute Section*/
		status = createandexesh(&tokens, &cont_com, en, av, &status);
		/*End of program*/
		free_all(&buffer, &tokens);
	} while (1);
	return (0);
}
