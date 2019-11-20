#include "headersh.h"

void get_path(path_node **list_path, char **en)
{
	char *variable_env =  NULL, *copyvari;
	int i;

	variable_env = _getenv("PATH", en);

	for (i = 0; variable_env[i] != '\0'; i++)
		;
	copyvari = malloc(sizeof(char) * (i + 1));
	for (i = 0; variable_env[i] != '\0'; i++)
		copyvari[i] = variable_env[i];
	copyvari[i] = '\0';

	*list_path = _getpathdir(copyvari);
}
