#include "headersh.h"

char *_getenv(const char *variable_env, char **en)
{
	int i, j, flag = 1;

	for (i = 0; en[i] != NULL; i++, flag = 1)
	{
		for (j = 0; en[i][j] != '='; j++)
		{
			if (variable_env[j] != en[i][j])
			{
				flag = 0;
				break;
			}
		}
		if (flag != 0)
			return (&(en[i][j + 1]));
	}
	return (NULL);
}
