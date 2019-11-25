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
 *add_path - adds the correct path to the command typed
 *@tokens: string with parsed input line
 *@en: environ global variable
 *Return: 0
 */
int add_path(char ***tokens, char **en)
{
	struct stat st;
	char *firstOne = NULL, *copyPath = NULL;
	int lenOne, lenTwo;
	path_node *list_path, *copylispa;

	if (tokens == NULL)
		return (0);

	get_path(&list_path, en);
	if (list_path == NULL)
		return (0);
	copylispa = list_path;
	firstOne = *(tokens)[0];
	lenOne = _strlen(firstOne);
	while (list_path != NULL)
	{
		lenTwo = _strlen(list_path->str);
		copyPath = malloc((lenTwo + lenOne + 2) * sizeof(char));
		copyPath[0] = '\0';
		_strcat(copyPath, list_path->str);
		_strcat(copyPath, "/");
		_strcat(copyPath, firstOne);
		if (stat(copyPath, &st) == 0)
		{
			(*tokens)[0] = copyPath;
			free_list(copylispa);
			return (1);
		}
		free(copyPath);
		copyPath = NULL;
		list_path = list_path->next;
	}
	free_list(copylispa);
	return (0);
}
