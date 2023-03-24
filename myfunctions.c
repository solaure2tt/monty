#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
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
	stack_t *t = *h;

	if (t != NULL)
	{
		while (t != NULL)
		{
			fprintf(stdout, "%d\n", (t)->n);
			t = (t)->next;
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
		fprintf(stdout, "%d\n", (*t)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", x);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_pop - remove an element in a stack
 * Description: remove an element in a top of stack
 * @t: stack
 * @x: line
 * Return: nothing
 */
void op_pop(stack_t **t, unsigned int x)
{
	stack_t *tmp;

	tmp = *t;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", x);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (tmp->next == NULL)
		{
			*t = NULL;
			free(tmp);
		}
		else
		{
			(*t) = tmp->next;
			(*t)->prev = NULL;
			free(tmp);
		}
	}
}

/**
 * op_swap - swap element in a stack
 * Description: swap the two element in a top of stack
 * @t: stack
 * @x: line
 * Return: nothing
 */
void op_swap(stack_t **t, unsigned int x)
{
	stack_t *node, *tmp;

	tmp = *t;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", x);
		exit(EXIT_FAILURE);
	}
	else
	{
		node = tmp->next;
		if (tmp->next->next == NULL)
		{
			tmp->next = node->next;
			node->next = tmp;
			tmp->prev = node;
			*t = node;
		}
		else
		{
			tmp->next = node->next;
			node->next->prev = tmp;
			node->next = tmp;
			tmp->prev = node;
			*t = node;
		}
	}
}
