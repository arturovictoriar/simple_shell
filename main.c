#include "headersh.h"

int main(void)
{
	char *buffer = NULL, **tokens;
	int len = 0;
	
	while(1)
	{
		/*Our shell prompt*/
		printf("($) ");

		/* READ section*/
		readsh(&buffer, &len);

		/*Parse section*/
		parsesh(&buffer, &len, &tokens);

		/*Create/Execute Section*/
		createandexesh(&tokens);

		/*End of program*/

		free(buffer);
		free(tokens);
	}
}
