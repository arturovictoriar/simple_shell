#include "headersh.h"

/**
 * _getpathdir - gets the directories for the PATH variable parsed in a linked
 * list
 * @path: the string containing the whole string of the PATH variable without
 * the header
 * Return: the head node of the parsed linked list
 */
path_node *_getpathdir(char *path)
{
	char *token;
	path_node *head;
	path_node *pathNode;

	if (path == NULL)
		return (NULL);

	head = NULL;
	pathNode = malloc(sizeof(path_node));
	if (pathNode == NULL)
		return (NULL);

	token = strtok(path, ":");
	pathNode->str = token;
	pathNode->next = head;
	head = pathNode;
	while (token != NULL)
	{
		token = strtok(NULL, ":");
		if (token == NULL) /* Don't save token NULL in list */
			break;
		pathNode = malloc(sizeof(path_node));
		if (pathNode == NULL)
			return (NULL);
		pathNode->str = token;
		pathNode->next = head;
		head = pathNode;
	}

	return (head);
}
