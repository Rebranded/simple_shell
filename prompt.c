#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * prompt - A function that displays a prompt and takes in arguements
 * @env: Environment variable
 * @is_pipe: Flag indicating weda input is from a pipe (1) or command line (0)
 * Return: 0, on success
 */

int prompt(char **env, int is_pipe);
void perform_env(char **env);

int prompt(char **env, int is_pipe)
{
	char *str = NULL;
	size_t size = 0;
	ssize_t byte;
	char *args[MAX_COMMAND];
	int p, t;
	pid_t child_pid;

	int is_terminal = isatty(STDIN_FILENO);
	int status;

	while (1)
	{

		if (is_pipe)
		{

			byte = getline(&str, &size, stdin);
		}
		else
		{
			/*if (is_terminal)*/
			/*{*/
			/*write(STDOUT_FILENO, "cisfun$ ", 8);*/
			/*}*/
			byte = getline(&str, &size, stdin);
			if (!is_terminal && byte  == -1)
			{
				free(str);
				break; /* End of pipe input */
			}
		}

		if (byte == -1)
		{
			free(str);
			break;
		}

		p = 0;
		while (str[p])
		{
			if (str[p] == '\n')
			{
				str[p] = 0;
			}
			p++;
		}

		t = 0;
		args[t] = strtok(str, " \t\r\n");
		while (args[t])
		{
			if (args[t][0] == '#')
			{
				args[t] = NULL;
				break;
			}

			t++;
			args[t] = strtok(NULL, " \t\r\n");
		}
		args[t] = NULL;

		if (args[0] && ak_strcmp(args[0], "exit") == 0)
		{
			free(str);
			if (!is_terminal)
			{
				break;
			}
			exit(2);
			break;
		}
		else if (args[0] && ak_strcmp(args[0], "env") == 0)
		{
			perform_env(env);
		}
		else if (args[0])
		{
			child_pid = fork();
			if (child_pid == 0)
			{
				if (execve(args[0], args, env) == -1)
				{
					exit(2);
					perror("hsh");
				}
				exit(1);
			}
			else
			{
				wait(&status);
			}
		}
	}

	return (0);
}

/**
 * perform_env - A function that handles environment
 * @env: double pointer to environment
 * This function prints the env variables.
 *
 * Return: 0, on sucess
 */
void perform_env(char **env)
{
	int p;

	for (p = 0; env[p] != NULL; p++)
	{
		write(STDOUT_FILENO, env[p], ak_strl(env[p]));
		write(STDOUT_FILENO, "\n", 1);

	}
}
