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
		int num_args = strtok(line, " ") == NULL ? 1 : strtok(NULL, " ") - line + 1;
		arguments = realloc(arguments, sizeof(char *) * num_args);

		while (arguments[i] = strtok(NULL, " "))
		{
			i++;
		}

		/* Check if command is built-in. */
		if (my_strcmp(arguments[0], "cd") == 0)
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
		} else if (my_strcmp(arguments[0], "env" == 0))
		{
			/* Print the environment. */
			char **envp = environ;
			while (*envp != NULL)
			{
				write(1, "%s=%s\n", *envp, *(envp + 1));
				envp += 2;
			} else if (my_strcmp(arguments[0], "exit") == 0)
			{
				/* Exit the hsh */
				if (arguments[1] != NULL)
				{
					int status = my_atoi(arguments[1]);
					write(1, "Exiting with status: %d\n", status);
				} else
				{
					write(1, "Exiting with status: 0\n");
				}
				break;
			} else
			{
				/* Execute the command. */
				char *command = arguments[0];
				char *dir;
				for (dir = strtok(path, ":"); dir != NULL, dir = strtok(NULL, ":"))
				{
					int fd = open(dir, O_RDONLY);

					if (fd != -1)
					{
						f = 1;
						int status = execve(dir + my_strlen(command) + 1, arguments, NULL);
						close(fd);
						if (status != 0)
						{
							write(1, "Error executing command: %d\n", status);
						}
						break;
					}
				}
				if (!f)
				{
					write(1, "Command not found: %s\n", command);
				}

				/* If the user presses Ctrl+D, exit the shell. */
				if (my_feof(stdin))
				{
					break;
				}

				/* Free the memory allocated for the arguments array. */
				free(arguments);
			return (0);
			}
		}
	}
}

