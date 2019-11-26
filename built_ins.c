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
 * cd - changes the current working directory
 * @tokens: the value to print
 * @en: environ variable
 * @buffer: read it from user
 * Return: nothing
 */

int cd(char **en, char ***tokens, char **buffer)
{
	int ret;
	char *home_env = NULL, *prewd = NULL;

	(void) buffer;
	home_env = _getenv("HOME", en);
	prewd = _getenv("PWD", en);
	if ((*tokens)[1] == NULL || _strcmp((*tokens)[1], "~") == 0 ||
	    _strcmp((*tokens)[1], "$HOME") == 0)
		ret = chdir(home_env);
	if (_strcmp((*tokens)[1], "-") == 0)
		ret = chdir(prewd);
	ret = chdir((*tokens)[1]);
	return (ret);
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
	{"cd", cd},
	{NULL, NULL},
	};

	for (j = 0; o[j].op != NULL; j++)
		if (_strcmp((*tokens)[0], o[j].op) == 0)
			return (o[j].f(en, tokens, buffer));
	return (0);
}
