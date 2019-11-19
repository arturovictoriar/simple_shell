#ifndef HEADERSH
#define HEADERSH

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;

void readsh(char **buffer, int *len, int *status);
void parsesh(char **buffer, int *len, char ***tokens, int *status);
void createandexesh(char ***tokens, int *status);
void _strtok(void);
size_t _getline(char **buffer, size_t *sizebuf, int *stream);
char *_getenv(const char *variable_env);
#endif
