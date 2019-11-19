#include "headersh.h"

void add_path(char ***tokens)
{
	char *variable_env =  NULL;
	path_node *list_path, *savepoin;


	(void) tokens;
	variable_env = _getenv("PATH");
	list_path = _getpathdir(variable_env);

	if (list_path != NULL)
	{
		while (list_path != NULL)
		{
			savepoin = list_path->next;
			free(list_path);
			list_path = savepoin;
		}
		free(list_path);
	}
}
