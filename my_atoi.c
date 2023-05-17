#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

/**
 * my_atoi - Convert a string to an integer
 * @str: String to convert
 *
 * Description: Converts the string @str to an integer.
 *
 * Return: The converted integer value of @str,  
 *	Otherwise 0 if @str does not start with a valid.
 */
int my_atoi(const char *str)
{
	int i = 0;
	int num = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
		}
		else
		{
			break:
		}
		i++;
	}
	return (num);
}
