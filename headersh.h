#ifndef HEADERSH
#define HEADERSH

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
  * struct path_node - singly linked list
  * @str: string - it a path directory
  * @next: points to the next node
  *
  * Description: Store all the path directories
  */

typedef struct path_node
{
	char *str;
	struct path_node *next;
} path_node;

/**
  * struct op - Struct op
  *
  * @op: The operator
  * @f: The function associated
  */
typedef struct op
{
	char *op;
	int (*f)(char **, char ***, char **);
} op_t;

int simple_sh(char **av, char **en);
int readsh(char **buffer, int *len);
void parsesh(char **buffer, int *len, char ***tokens, int *status);
int createandexesh(char ***, int *, char **, char **);
void _strtok(void);
size_t _getline(char **buffer, size_t *sizebuf, int *stream);
char *_getenv(const char *variable_env, char **en);
path_node *_getpathdir(char *path);
int add_path(char ***tokens, char **en);
void get_path(path_node **list_path, char **en);
int _strcmp(char *s1, char *s2);
void free_list(path_node *list_path);
void free_all(char **buffer, char ***tokens);
int built_ins_sh(char ***tokens, char **en, char **buffer);
#endif
