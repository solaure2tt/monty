#include "monty.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFFER_MAX_LENGTH 1024

/**
 * _isdigit - function
 * Description: function that checks for digit
 * @c: parameter
 * Return: 1 if true 0 if false
 */
int _isdigit(char *c)
{
	int r = 1;
	int i = strlen(c);
	int j;

	j = 0;
	printf("taille de %s est %d\n", c, i);
	if (i == 0)
		return (0);
	while (j < i)
	{
		if (c[j] >= '0' && c[j] <= '9')
			continue;
		else
		{
			r = 0;
			break;
		}
		j++;
	}
	return (r);
}

/**
 * read_file - read a file
 * Description: read a file line by line
 * @fd: descriptor of the file to read
 * Return: integer status
 */
int read_file(FILE *fd)
{
        char line[BUFFER_MAX_LENGTH];
        char *p, d[] = " ";
        int c;
	unsigned int lin = 0;

        while (fgets(line, sizeof(line), fd))
        {
                lin++;
                if (strcmp(line, "") == 0)
                        continue;
                else
                {
                        p = strtok(line, d);
                        while (p != NULL)
                        {
                                c = 1;
                                if (strcmp(p, "push") == 0)
                                {
                                        p = strtok(NULL, d);
                                        if (p != NULL)
                                                op_f("push", atoi(p));
                                        else
					{
                                                fprintf(stderr, "L%d: usage: push integer\n", lin);
						exit(EXIT_FAILURE);
					}
                                        c++;
                                        if (c == 2)
                                                break;
                                }
				else if (strstr(p, "pint") != NULL)
				{
					op_f("pint", lin);
					break;
				}
				else if (strstr(p, "pall") != NULL)
				{
					op_f("pall", lin);
					break;
				}
			}
                }
        }
        return (0);
}
