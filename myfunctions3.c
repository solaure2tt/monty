#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * op_pchar - char at the top of the stack,
 * Description: print a char at the top of the stack,
 * @t: stack
 * @x: line
 * Return: nothing
 */
void op_pchar(stack_t **t, unsigned int x)
{
	stack_t *tmp;

	tmp = *t;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack too short\n", x);
		exit(EXIT_FAILURE);
	}
	else if (tmp->n > 127 || tmp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", x);
		exit(EXIT_FAILURE);
	}
	else
		fprintf(stdout, "%c\n", tmp->n);
}

/**
 * op_pstr - prints the string starting at the top of the stack
 * Description: prints the string starting at the top of the stack
 * @t: stack
 * @x: line
 * Return: nothing
 */
void op_pstr(stack_t **t, __attribute__((unused)) unsigned int x)
{
	stack_t *tmp = *t;

	if (tmp == NULL)
	{
		fprintf(stdout, "\n");
		exit(0);
	}
	while (tmp != NULL)
	{
		if (tmp->n > 127 || tmp->n <= 0)
		{
			fprintf(stdout, "\n");
			exit(0);
		}
		else
			fprintf(stdout, "%c", tmp->n);
		tmp = tmp->next;
	}
	fprintf(stdout, "\n");
}
