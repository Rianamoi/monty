#include "monty.h"

/**
 * push - push int to stack ds
 * @stack: stack ds
 * @n: value to push
 *
 * Return: void
 */

void push(_stack_t **stack, unsigned int n)
{
	_stack_t *new = malloc(sizeof(_stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - print stack
 * @stack: stack ds
 * @n: potential line number
 *
 * Return: void
 */

void pall(_stack_t **stack, __attribute__((unused)) unsigned int n)
{
	_stack_t *tmp = *stack;

	while (tmp->next)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - print top val in stack
 * @stack: stack ds
 * @n: potential line number
 *
 * Return: void
 */

void pint(_stack_t **stack, __attribute__((unused)) unsigned int n)
{
	_stack_t *tmp = *stack;

	if (tmp->next)
		printf("%d\n", tmp->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - remove top val in stack
 * @stack: stack ds
 * @n: potential line number
 *
 * Return: void
 */

void pop(_stack_t **stack, __attribute__((unused)) unsigned int n)
{
	if (*stack && isint((*stack)))
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", n);
		exit(EXIT_FAILURE);
	}
}

/**
 * swap - swap top 2 vals in stack
 * @stack: stack ds
 * @n: potential line number
 *
 * Return: void
 */

void swap(_stack_t **stack, __attribute__((unused)) unsigned int n)
{
	unsigned int tmp;

	if (*stack && isint((*stack)) && isint((*stack)->next))
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
}
