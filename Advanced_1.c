#include "monty.h"

/**
 * add - add the top 2 vals in stack
 * @stack: stack ds
 * @n: potential line number
 *
 * Return: void
 */

void add(_stack_t **stack, __attribute__((unused)) unsigned int n)
{
	_stack_t *tmp = malloc(sizeof(_stack_t));

	if (*stack && isint((*stack)) && isint((*stack)->next))
	{
		tmp = (*stack)->next;
		tmp->n = tmp->n + (*stack)->n;
		*stack = tmp;
		(*stack)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop - does nothing
 * @stack: stack ds
 * @n: potential line number
 *
 * Return: void
 */

void nop(_stack_t **stack, __attribute__((unused)) unsigned int n)
{
	(void)stack;
	(void)n;
}

/**
 * sub - subtract the top val from 2 top val in stack
 * @stack: stack ds
 * @n: potential line number
 *
 * Return: void
 */

void sub(_stack_t **stack, __attribute__((unused)) unsigned int n)
{
	_stack_t *tmp = malloc(sizeof(_stack_t));

	if (*stack && isint((*stack)) && isint((*stack)->next))
	{
		tmp = (*stack)->next;
		tmp->n = tmp->n - (*stack)->n;
		*stack = tmp;
		(*stack)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
}

/**
 * _div - divide the 2nd top val by top val in stack
 * @stack: stack ds
 * @n: potential line number
 *
 * Return: void
 */

void _div(_stack_t **stack, __attribute__((unused)) unsigned int n)
{
	_stack_t *tmp = malloc(sizeof(_stack_t));

	if (*stack && isint((*stack)) && isint((*stack)->next))
	{
		tmp = (*stack)->next;
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", n);
			exit(EXIT_FAILURE);
		}	
		tmp->n = (*stack)->n / tmp->n;
		*stack = tmp;
		(*stack)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul - multiply 2nd top val by the top val in stack
 * @stack: stack ds
 * @n: potential line number
 *
 * Return: void
 */

void mul(_stack_t **stack, __attribute__((unused)) unsigned int n)
{
	_stack_t *tmp = malloc(sizeof(_stack_t));

	if (*stack && isint((*stack)) && isint((*stack)->next))
	{
		tmp = (*stack)->next;
		tmp->n = tmp->n * (*stack)->n;
		*stack = tmp;
		(*stack)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
}
