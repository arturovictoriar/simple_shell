#include "headersh.h"

char *_getenv(const char *variable_env)
{
	int i, j, flag = 1;

	for (i = 0; environ[i] != NULL; i++, flag = 1)
	{
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (variable_env[j] != environ[i][j])
			{
				flag = 0;
				break;
			}
		}
		if (flag != 0)
			return (&(environ[i][j + 1]));
	}
	return (NULL);
}
