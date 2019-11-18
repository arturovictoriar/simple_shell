#include "headersh.h"

void parsesh(char **buffer, int *len, char ***tokens, int *status)
{
	char *token;
	int i;
	const char delim[] = " ";

	(void) status;
	*tokens = malloc(sizeof(char *) * (*len + 1));
	if (*tokens == NULL)
	{
		printf("Error puto\n");
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
