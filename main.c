#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t _getline(char **buffer, size_t *sizebuf, int *stream)
{
	ssize_t status;

	*buffer = malloc(sizeof(char) * 120);
	
	if (*buffer == NULL)
	{
		printf("Error");
		return (0);
	}

	status = read(*stream, *buffer, *sizebuf);
	
	if (status == -1)
	{
		printf("Error\n");
		return (0);
	}

	/*(*buffer)[status] = '\0';*/

	/*printf("%s, %zd\n", *buffer, status);*/

	return(status);
}

int main(void)
{
	size_t status = 0, sizebuf = 120;
	char *buffer = NULL;

	printf("$ ");
	status = _getline(&buffer, &sizebuf, STDIN_FILENO);

	free(buffer);
}
