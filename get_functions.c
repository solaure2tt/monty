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
void op_f(char *s, int nu)
{

	__attribute__((unused)) instruction_t ops[3] = {
		{"push", &op_push},
		{"pall", &op_pall},
		{"pint", &op_pint}
	};

	if (strcmp(s, "push") == 0)
	{
		(ops[0].f)(&st, nu);
	}
	if (strcmp(s, "pall") == 0)
	{
		(ops[1].f)(&st, nu);
	}
	if (strcmp(s, "pint") == 0)
        {
                (ops[2].f)(&st, nu);
        }
}
