#include "headersh.h"

int main(void)
{
	char *buffer = NULL, **tokens;
	int len = 0, status;
	
	while(1)
	{
		status = 0;
		/*Our shell prompt*/
		if (isatty(STDIN_FILENO))
			write(1, "($)", 4);

		/*READ section*/
		readsh(&buffer, &len, &status);
		/*Breaks cases*/
		printf("%i\n", status);
		if (status == 1)
			continue;

		if (status == 2)
			return(1);

		/*Parse section*/
		parsesh(&buffer, &len, &tokens, &status);

		/*Create/Execute Section*/
		createandexesh(&tokens, &status);

		/*End of program*/
		if (status == 0)
		{
			free(buffer);
			free(tokens);
		}

		if (status == 3)
			return(1);

		/*Interactive or not interactive mode*/
		if (!isatty(STDIN_FILENO))
			return (1);
	}
}
