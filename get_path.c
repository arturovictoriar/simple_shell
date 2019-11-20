#include "headersh.h"

void get_path(path_node **list_path, char **en)
{
	char *variable_env =  NULL;

	variable_env = _getenv("PATH", en);
	*list_path = _getpathdir(variable_env);
}
