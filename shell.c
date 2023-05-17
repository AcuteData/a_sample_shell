#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

/**
 * main - runs a simple shell program
 *
 * Return: 0 on success
 */
int main(void)
{
	char *command;
	int status;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		command = getline(NULL, 0, stdin);
		if (command == NULL)
			break;

		pid_t pid = fork();
		if (pid == 0)
		{
			execve(command, NULL, environ);
			perror(command);
			exit(1);
		}

		wait(&status);
	}
	return (0);
}
