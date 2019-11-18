#ifndef HEADERSH
#define HEADERSH

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void readsh(char **buffer, int *len);
void parsesh(char **buffer, int *len, char ***tokens);
void createandexesh(char ***tokens);
void _strtok(void);
size_t _getline(char **buffer, size_t *sizebuf, int *stream);
#endif
