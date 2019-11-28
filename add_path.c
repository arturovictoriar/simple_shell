#include "headersh.h"

/**
 *_strlen - gets the length of a string
 *@st: string that will be input to the function
 *Return: the length of @st
 */
int _strlen(char *st)
{
	int i = 0;

	for (i = 0; st[i] != '\0'; i++)
		;
	return (i);
}

/**
* _strcat - check the code for Holberton School students.
* @dest: is a pointer type char
* @src: is a pointer type char
* Return: Always 0.
*/
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	dest[i + j] = '\0';
	return (dest);
}
/**
 *add_pwd - adds the correct path to the command typed
 *@tokens: string with parsed input line
 *@en: environ global variable
 *Return: Nothing
 */
void add_pwd(char ***tokens, char **en)
{
	char *cwd = NULL, *token = NULL;

	cwd = _getenv("PWD", en);
	token = strtok((*tokens)[0], ".");
	_strcat(cwd, token);
	(*tokens)[0] = cwd;
}

/**
 *add_path - adds the correct path to the command typed
 *@tokens: string with parsed input line
 *@en: environ global variable
 *Return: 0
 */
int add_path(char ***tokens, char **en)
{
	char *com_user = NULL, *new_path = NULL;
	int lencom_user, len_dir;
	path_node *list_path, *copylispa;

	if (tokens == NULL)
		return (0);

	if ((*tokens)[0][0] == '.' && (*tokens)[0][1] == '/')
	{
		add_pwd(tokens, en);
		return (0);
	}
	get_path(&list_path, en);
	if (list_path == NULL)
		return (0);
	copylispa = list_path;
	com_user = *(tokens)[0];
	lencom_user = _strlen(com_user);
	while (list_path != NULL)
	{
		len_dir = _strlen(list_path->str);
		new_path = malloc((len_dir + lencom_user + 2) * sizeof(char));
		new_path[0] = '\0';
		_strcat(new_path, list_path->str);
		_strcat(new_path, "/");
		_strcat(new_path, com_user);
		if (access(new_path, F_OK | X_OK) == 0)
		{
			(*tokens)[0] = new_path;
			free_list(copylispa);
			return (1);
		}
		free(new_path);
		new_path = NULL;
		list_path = list_path->next;
	}
	free_list(copylispa);
	return (0);
}
