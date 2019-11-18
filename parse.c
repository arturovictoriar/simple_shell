#include "headersh.h"

void parsesh(char **buffer, int *len, char ***tokens)
{
	char *token;
	int i;
	const char delim[] = " ";

	*tokens = malloc(sizeof(char *) * (*len + 1));
	if (*tokens == NULL)
	{
		printf("Error\n");
		return;
	}
	token = strtok(*buffer, delim);
	for (i = 0; token != NULL; i++)
	{
		(*tokens)[i] = token;
		token = strtok(NULL, delim);
	}
	(*tokens)[i] = token;
}
