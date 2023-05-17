#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* SHS.C */
int main(void);

/* MY_ATOI */
int custom_atoi(const char *str);

/* MY_STRCMP */
int my_strcmp(const char *str1, const char *str2);

/* MY_FEOF */
int my_feof(FILE *stream);

#endif

