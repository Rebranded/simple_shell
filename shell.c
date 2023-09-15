#include "shell.h"
#include <unistd.h>
#include <string.h>
/**
 * main - shell function
 * @ac: The number of items in av
 * @av: Null terminated array of strings
 * @env: Environment Variable
 * Return: 0, on success
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
	{
		prompt(env, 0);
	}
	else
	{

		prompt(env, 1);
		write(STDOUT_FILENO, av[0], ak_strl(av[0]));
		write(STDOUT_FILENO, ": error\n", 8);
	}
	return (0);
}
