#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

ssize_t _getline(char **buffer, size_t *sizebuf, int *stream)
{
	ssize_t status;

	*buffer = malloc(sizeof(char) * (*sizebuf));
	
	if (*buffer == NULL)
	{
		printf("Error");
		return (0);
	}

	status = read(0, *buffer, *sizebuf);
	
	if (status == -1)
	{
		printf("Error\n");
		return (0);
	}

	(*buffer)[status] = '\0';

	printf("%s, %zd\n", *buffer, status);

	return(status);
}

int main(void)
{
	ssize_t status = 0, sizebuf = 20;
	char *buffer = NULL, *copybuffer = NULL, *token, **tokens;
	const char delim[2] = " ";
	int i = 0;

	/*Our shell prompt*/
	printf("$ ");

	/* READ part*/
	status = getline(&buffer, &sizebuf, stdin);
	if (status == -1)
	{
	        printf("Error\n");
		return (0);
	}

	printf("Read part: %s, %zd\n", buffer, status);
	
	/*copybuffer*/
	copybuffer = malloc(sizeof(char) * status + 1);
	for (i = 0; buffer[i] != '\0'; i++)
		copybuffer[i] = buffer[i];
	copybuffer[i] = '\0';

	printf("Copybuffer: %s, %i\n", copybuffer, i);

	token = strtok(copybuffer, delim);
	for (i = 0; token != NULL; i++)
		token = strtok(NULL, delim);
	free(copybuffer);

	/*Parse part*/
	tokens = malloc(sizeof(char *) * i);
	if (tokens == NULL)
	{
		printf("Error\n");
		return (0);
	}

	token = strtok(buffer, delim);
	printf("Parse part: ");

	for (i = 0; token != NULL; i++)
	{
		tokens[i] = token;
		printf("%s, ", tokens[i]);
	        token = strtok(NULL, delim);
	}

	printf("\n");



	free(buffer);
	free(tokens);
}
