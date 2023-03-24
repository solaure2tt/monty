#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
stack_t *st = NULL;

/**
 * main - entry
 * Description: open a monty file and execute it
 * @ac: number of arguments
 * @av:list of arguments
 * Return: an integer
 */

int main(int ac, char *av[])
{
	FILE *fd;
	int res;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	res = read_file(fd);
	return (res);

}
