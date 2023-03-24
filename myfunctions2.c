#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * op_sub - substract an element in a stack
 * Description: substract the two element in a top of stack
 * @t: stack
 * @x: line
 * Return: nothing
 */
void op_sub(stack_t **t, unsigned int x)
{
	stack_t *tmp = *t;

	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", x);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp->next->n = tmp->next->n - tmp->n;
		*t = tmp->next;
		(*t)->prev = NULL;
		free(tmp);
	}
}

/**
 * op_div - divide an element in a stack
 * Description: divide the two element in a top of stack
 * @t: stack
 * @x: line
 * Return: nothing
 */
void op_div(stack_t **t, unsigned int x)
{
	stack_t *tmp = *t;

	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", x);
		exit(EXIT_FAILURE);
	}
	else if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", x);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp->next->n = tmp->next->n / tmp->n;
		*t = tmp->next;
		(*t)->prev = NULL;
		free(tmp);
	}
}

/**
 * op_mul - muliply an element in a stack
 * Description: multiply the two element in a top of stack
 * @t: stack
 * @x: line
 * Return: nothing
 */
void op_mul(stack_t **t, unsigned int x)
{
	stack_t *tmp;

	tmp = *t;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", x);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp->next->n = (tmp->next->n) * (tmp->n);
		*t = tmp->next;
		(*t)->prev = NULL;
		free(tmp);
	}
}

/**
 * op_mod - rest of division an element in a stack
 * Description: rest of division the two element in a top of stack
 * @t: stack
 * @x: line
 * Return: nothing
 */
void op_mod(stack_t **t, unsigned int x)
{
	stack_t *tmp = *t;

	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", x);
		exit(EXIT_FAILURE);
	}
	else if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", x);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp->next->n = tmp->next->n % tmp->n;
		*t = tmp->next;
		(*t)->prev = NULL;
		free(tmp);
	}
}
