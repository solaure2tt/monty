#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>

/**
 * op_push - add a new element in a stack
 * Description: add a new element in a top of stack
 * @t: stack
 * @x: inteer to add
 * Return: nothing
 */
void op_push(stack_t **t, unsigned int x)
{
	stack_t *node;

	node = (stack_t *)malloc(sizeof(stack_t));
	if (node != NULL)
	{
		node->n = x;
		if (t == NULL)
		{
			node->next = NULL;
		}
		else
		{
			node->next = *t;
		}
		node->prev = NULL;
		if ((*t) != NULL)
			(*t)->prev = node;
		*t = node;
	}
}


/**
 * op_pall - print stack
 * Description: prints all the elements of a stack
 * @h: stack
 * @x: line
 * Return: nothing
 */
void op_pall(stack_t **h, __attribute__((unused)) unsigned int x)
{
	stack_t **t = h;

	if (*t != NULL)
	{
		while (*t != NULL)
		{
			printf("%d\n", (*t)->n);
			*t = (*t)->next;
		}
	}
}

/**
 * op_pint - print stack
 * Description: prints  the elements in top of a stack
 * @h: stack
 * @x: line
 * Return: nothing
 */
void op_pint(stack_t **h, __attribute__((unused)) unsigned int x)
{
	stack_t **t = h;

	if (*t != NULL)
		printf("%d\n", (*t)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", x);
		exit(EXIT_FAILURE);
	}
}
