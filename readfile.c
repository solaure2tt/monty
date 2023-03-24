#include "monty.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>

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
		if (strcmp(line, "") != 0)
		{
			p = strtok(line, d);
			while (p != NULL)
			{
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
