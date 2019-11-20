#include "headersh.h"

int _strlen(char *st)
{
	int i;

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

int add_path(char ***tokens, path_node *list_path)
{
	struct stat st;
	char *firstOne = NULL, *copyPath = NULL;
	int lenOne, lenTwo;

	if (tokens == NULL)
		return (0);

	if (list_path == NULL)
		return (0);
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
			return (1);
		}
		free(copyPath);
		copyPath = NULL;
		list_path = list_path->next;
	}
	return (0);
}
