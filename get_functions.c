#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * op_f - get function
 * Description: get the op code to execute
 * @s: opcode
 * @nu: line
 * Return: Nothing
 */
void op_f(char *s, unsigned int nu)
{

	__attribute__((unused)) instruction_t ops[10] = {
		{"push", &op_push},
		{"pall", &op_pall},
		{"pint", &op_pint},
		{"pop", &op_pop},
		{"swap", &op_swap},
		{"add", &op_add},
		{"sub", &op_sub},
		{"div", &op_div},
		{"mul", &op_mul},
		{"mod", &op_mod}
	};

	if (strcmp(s, "push") == 0)
		(ops[0].f)(&st, nu);
	if (strcmp(s, "pall") == 0)
		(ops[1].f)(&st, nu);
	if (strcmp(s, "pint") == 0)
		(ops[2].f)(&st, nu);
	if (strcmp(s, "pop") == 0)
		(ops[3].f)(&st, nu);
	if (strcmp(s, "swap") == 0)
		(ops[4].f)(&st, nu);
	if (strcmp(s, "add") == 0)
		(ops[5].f)(&st, nu);
	if (strcmp(s, "nop") == 0)
	{
	}
	if (strcmp(s, "sub") == 0)
		(ops[6].f)(&st, nu);
	if (strcmp(s, "div") == 0)
		(ops[7].f)(&st, nu);
	if (strcmp(s, "mul") == 0)
		(ops[8].f)(&st, nu);
	if (strcmp(s, "mod") == 0)
		(ops[9].f)(&st, nu);
}

/**
 * op_add - add an element in a stack
 * Description: add the two element in a top of stack
 * @t: stack
 * @x: line
 * Return: nothing
 */
void op_add(stack_t **t, unsigned int x)
{
	stack_t *tmp;

	tmp = *t;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", x);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp->next->n = tmp->n + tmp->next->n;
		*t = tmp->next;
		(*t)->prev = NULL;
		free(tmp);
	}
}

