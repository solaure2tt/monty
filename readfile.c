#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
/**
 * is_integer - verify if it is an integer
 * Description: verify if a string is integer
 * @c: string
 * Return: 0 or 1
 */
int is_integer(char *c)
{
	int j, res = 1;
	int len = strlen(c);

	if (len <= 0)
		return (0);
	j = 0;
	while (j < len)
	{
		if (c[j] >= '0' && c[j] <= '9')
			j++;
		else
			return (0);
	}
	return (res);
}

/**
 * read_file - read a file
 * Description: read a file line by line
 * @fd: descriptor of the file to read
 * Return: integer status
 */
int read_file(FILE *fd)
{
	char line[1024], *p, d[] = " ";
	unsigned int lin = 0;

	while (fgets(line, sizeof(line), fd))
	{
		lin++;
		line[strlen(line) - 1] = '\0';
		if (strcmp(line, "") != 0)
		{
			p = strtok(line, d);
			while (p != NULL)
			{
				if (strcmp(p, "push") == 0)
				{
					p = strtok(NULL, d);
					if (p != NULL && strlen(p) != 0 && is_integer(p) != 0)
						op_f("push", atoi(p));
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", lin);
						exit(EXIT_FAILURE);
					}
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
