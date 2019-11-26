#include "headersh.h"

/**
  * env - fills memory with a constant byte
  * @tokens: the value to print
  * @en: environ variable
  * @buffer: read it from user
  * Return: nothing
  */

int env(char **en, char ***tokens, char **buffer)
{
	int i, j;

	(void) tokens;
	(void) buffer;
	for (i = 0; en[i] != NULL; i++)
	{
		for (j = 0; en[i][j] != '\0'; j++)
			continue;
		write(STDOUT_FILENO, en[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}

/**
  * exi - fills memory with a constant byte
  * @tokens: the value to print
  * @en: environ variable
  * @buffer: read it from user
  * Return: nothing
 */

int exi(char **en, char ***tokens, char **buffer)
{

	(void) en;
	free_all(buffer, tokens);
	exit(0);
}

/**
  * built_ins_sh - fills memory with a constant byte
  * @tokens: the value to print
  * @en: environ variable
  * @buffer: read it from user
  * Return: numbers of characters printed
  */

int built_ins_sh(char ***tokens, char **en, char **buffer)
{
	int j;
	op_t o[] = {
	{"env", env},
	{"exit", exi},
	{NULL, NULL},
	};

	for (j = 0; o[j].op != NULL; j++)
		if (_strcmp((*tokens)[0], o[j].op) == 0)
			return (o[j].f(en, tokens, buffer));
	return (0);
}
