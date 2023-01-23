#include "monty.h"

/**
 * mod - modulo the 2nd top val by top val in stack
 * @stack: stack ds
 * @n: potential line number
 *
 * Return: void
 */

void mod(_stack_t **stack, __attribute__((unused)) unsigned int n)
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
		tmp->n = (*stack)->n % tmp->n;
		*stack = tmp;
		(*stack)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
}

/**
 * pchar - print ascii of top val in stack
 * @stack: stack ds
 * @n: potential line number
 *
 * Return: void
 */

void pchar(_stack_t **stack, __attribute__((unused)) unsigned int n)
{
	_stack_t *tmp = *stack;

	if (!tmp->next)
	{
		fprintf(stderr, "L%u: can't pchar, stack is empty\n", n);
		exit(EXIT_FAILURE);
	}

	if (tmp->next && (tmp->n >= 0 && tmp->n < 178))
		printf("%c\n", tmp->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", n);
		exit(EXIT_FAILURE);
	}
}
