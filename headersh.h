#ifndef HEADERSH
#define HEADERSH

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

typedef struct path_node
{
	char *str;
	struct path_node *next;
} path_node;

void readsh(char **buffer, int *len, int *status);
void parsesh(char **buffer, int *len, char ***tokens, int *status);
void createandexesh(char ***, int *, char **, path_node *);
void _strtok(void);
size_t _getline(char **buffer, size_t *sizebuf, int *stream);
char *_getenv(const char *variable_env, char **en);
path_node *_getpathdir(char *path);
int add_path(char ***tokens, path_node *list_path);
void get_path(path_node **list_path, char **en);
#endif
