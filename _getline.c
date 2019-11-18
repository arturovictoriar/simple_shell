#include "headersh.h"

size_t _getline(char **buffer, size_t *sizebuf, int *stream)
{
	ssize_t status;
	*buffer = malloc(sizeof(char) * (*sizebuf));
	(void) stream;
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
