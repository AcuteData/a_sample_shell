#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

/**
 * my_strcmp - Compares two strings.
 * @str1: The first string to compare
 * @str2: The second string to compare
 *
 * Description: Compares strings @str1 and @str2.
 *
 * Return: An integer <, =, or > 0 if @str1 is <, =, or >  @str2.
 */
int my_strcmp(const char *str1, const char *str2)
{
	int k = 0;

	while (str1[k] != '\0' && str2[k] != '\0')
	{
		if (str1[k] != str2[k])
		{
			return str1[k] - str2[k];
		}
		k++;
	}
	return (str1[k] - str2[k]);
}	
