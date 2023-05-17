#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

/**
 * my_feof - Check if the end of file has been reached
 * @stream: The file stream to check
 *
 * Description: Checks if end of file associated with the file stream @stream
 * has been reached.
 *
 * Return: 1 if the end of file has been reached, 0 if not, or -1 on error.
 */
int my_feof(FILE *stream)
{
	int fd = fileno(stream);
	struct stat file_stat;

	if (fstat(fd, &file_stat) == -1)
		return (-1);

	off_t current_position;

	off_t current_position = lseek(fd, 0, SEEK_CUR);
	off_t end_position = file_stat.st_size;

	return (current_position == end_position);
}
