#include "headersh.h"

void readsh(char **buffer, int *len)
{
	ssize_t read = 0;
	size_t sizebuf = 20;
	char *copybuffer = NULL, *token;
	const char delim[] = " ";
	int i;
	
	/* READ section*/
	read = getline(buffer, &sizebuf, stdin);
	if (read == -1)
	{
		printf("Error\n");
		return;
	}
	/*copybuffer*/
	copybuffer = malloc(sizeof(char) * read);
	if (copybuffer == NULL)
	{
		printf("Error\n");
		return;
	}
	for (i = 0; buffer[0][i] != '\0'; i++)
		copybuffer[i] = buffer[0][i];
	i--;
	copybuffer[i] = '\0';
	buffer[0][i] = '\0';
	token = strtok(copybuffer, delim);
	for (i = 0; token != NULL; i++)
		token = strtok(NULL, delim);
	*len = i;
	free(copybuffer);
}
