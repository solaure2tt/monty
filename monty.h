#ifndef MONTY
#define MONTY
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
#ifdef DEFINE_VARIABLES
#define EXTERN
#else
#define EXTERN extern
#endif
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
	void (*f)(stack_t **stack, int line_number);
} instruction_t;

int openfile(char *path);
void op_push(stack_t **t, int x);
void op_pall(stack_t **st, int x);
void op_f(char *s, int num);
int read_file(FILE *fd);
void initialisation(void);
void op_pint(stack_t **st, int x);
#endif