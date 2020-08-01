#include "headersh.h"

/**
* main - call the shell by Arturo and Juani
* @ac: argument count
* @av: argument vector
* @en: external variable environment parsed by lines
* Return: nothing
*/

int main(int ac, char **av, char **en)
{
	if (ac == 1)
		return (simple_sh(av, en));

	return (0);
}
