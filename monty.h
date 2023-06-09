#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t *st;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int openfile(char *path);
void op_push(stack_t **t, unsigned int x);
void op_pall(stack_t **st, unsigned int x);
void op_f(char *s, unsigned int num);
void op_f2(char *s, unsigned int num);
int read_file(FILE *fd);
void initialisation(void);
void op_pint(stack_t **st, unsigned int x);
void op_pop(stack_t **t, unsigned int x);
void op_swap(stack_t **t, unsigned int x);
void op_add(stack_t **t, unsigned int x);
void op_nop(stack_t **t, unsigned int x);
void op_sub(stack_t **t, unsigned int x);
void op_div(stack_t **t, unsigned int x);
void op_mul(stack_t **t, unsigned int x);
void op_mod(stack_t **t, unsigned int x);
void op_pchar(stack_t **t, unsigned int x);
void op_pstr(stack_t **t, unsigned int x);
void op_rotl(stack_t **t, unsigned int x);
void op_rotr(stack_t **t, unsigned int x);
#endif
