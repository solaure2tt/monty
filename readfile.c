#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
/**
 * other_op - case of other opcode
 * Description: case of pint, pall, pop and swap
 * @ch: opcode
 * @li: line
 * Return: 0 or 1
 */
int other_op(char *ch, unsigned int li)
{
	if (strcmp(ch, "pint") == 0)
		op_f("pint", li);
	else if (strcmp(ch, "pall") == 0)
		op_f("pall", li);
	else if (strcmp(ch, "pop") == 0)
		op_f("pop", li);
	else if (strcmp(ch, "swap") == 0)
		op_f("swap", li);
	else if (strcmp(ch, "add") == 0)
		op_f("add", li);
	else if (strcmp(ch, "nop") == 0)
		op_f("nop", li);
	else if (strcmp(ch, "sub") == 0)
		op_f("sub", li);
	else if (strcmp(ch, "div") == 0)
		op_f("div", li);
	else if (strcmp(ch, "mul") == 0)
		op_f("mul", li);
	else if (strcmp(ch, "mod") == 0)
		op_f("mod", li);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", li, ch);
		return (1);
	}
	return (0);
}
/**
 * is_integer - verify if it is an integer
 * Description: verify if a string is integer
 * @c: string
 * Return: 0 or 10)
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
	unsigned int x, lin = 0;

	while (fgets(line, sizeof(line), fd))
	{
		lin++;
		line[strlen(line) - 1] = '\0';
		if (strcmp(line, "") != 0 && line[0] != '#')
		{
			p = strtok(line, d);
			while (p != NULL && p[0] != '#')
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
				else
				{
					x = other_op(p, lin);
					if (x == 1)
						exit(EXIT_FAILURE);
					break;
				}
			}
		}
	}
	return (0);
}
