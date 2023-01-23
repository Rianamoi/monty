#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} _stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(_stack_t **stack, unsigned int line_number);
} instruction_t;

void read_file(FILE *fd, _stack_t **stack);
void push(_stack_t **stack, unsigned int n);
void pall(_stack_t **stack, __attribute__((unused)) unsigned int n);
void pint(_stack_t **stack, __attribute__((unused)) unsigned int n);
void pop(_stack_t **stack, __attribute__((unused)) unsigned int n);
void swap(_stack_t **stack, __attribute__((unused)) unsigned int n);
void add(_stack_t **stack, __attribute__((unused)) unsigned int n);
void nop(_stack_t **stack, __attribute__((unused)) unsigned int n);
void sub(_stack_t **stack, __attribute__((unused)) unsigned int n);
void _div(_stack_t **stack, __attribute__((unused)) unsigned int n);
void mul(_stack_t **stack, __attribute__((unused)) unsigned int n);
void mod(_stack_t **stack, __attribute__((unused)) unsigned int n);
void pchar(_stack_t **stack, __attribute__((unused)) unsigned int n);
void free_stack_t(_stack_t *head);
char *strip(char **str);
void (*get_op(char *opcode))(_stack_t **, unsigned int);
char **tokens(char *cmd);
int isint(_stack_t *node);

#endif
