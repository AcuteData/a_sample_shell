#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

/**
 * main - Entry point for the shell program.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	char line[100];
	char **arguments;
	char *path = getenv("PATH");
	int i = 0;
	int f = 0;

	while (1)
	{
		/* Print a prompt */
		write(1, "#hsh$ ", 10);

		/* Read a line of input from the user */
		int n = getline(line, 100);

		if (n == -1)
		{
			break;
		}

		/* Parse the input line */
		arguments = malloc(sizeof(char *));
		int num_args = strtok(line, " ") ? 1 : strtok(NULL, " ") - line + 1;
		arguments = realloc(arguments, sizeof(char *) * num_args);

		while (arguments[i++] = strtok(NULL, " "))
		{
		}

		/* Check if command is built-in. */
		if (strcmp(arguments[0], "cd") == 0)
		{
			/* Change directory */
			char *directory = arguments[1];
			if (directory == NULL)
			{
				write(1, "cd: missing directory\n");
			} else
			{
				int status = chdir(directory);
				if (status !=0)
				{
					write(1, "cd: %s: No such file or directory\n", directory);
				}
			}
		} else if (strcmp(arguments[0], "env" == 0))
		{
			/* Print the environment. */
			char **envp = environ;
			while (*envp != NULL)
			{
				write(1, "%s=%s\n", *envp, *(envp + 1));
				envp += 2;
			} 
		} else if (strcmp(arguments[0], "exit") == 0)
		{
			/* Exit the hsh */
			if (arguments[1] != NULL)
			{
				int status = atoi(arguments[1]);
				write(1, "Exiting with status: %d\n", status);
			} else
			{
				write(1, "Exiting\n");
			}
			return (0);
		} else
		{
			/* Execute the command. */
			char *command = arguments[0];

			for (dir = strtok(path, ":"); dir != NULL, dir = strtok(NULL, ":"))
			{
				int status = execve(dir + strlen(command) + 1, arguments, NULL);
				if ( status == 0)
				{
					break;
				}
			}
			if (status != 0)
			{
				write(1, "Command not found: %s\n", command);
			}
		}
	}
	return (0);
}
