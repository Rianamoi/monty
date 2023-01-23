#include "monty.h"

/**
 * get_rotl - function that rotates the tail to the top
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * Description: 13. rotl
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */
void get_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		;
	}
	else
	{
		first = last = *stack;
		while (last->next)
		{
			last = last->next;
		}
		*stack = first->next;
		last->next = first;
		first->prev = last;
		first->next = NULL;
		(*stack)->prev = NULL;
	}
}


/**
 *  get_rotr - Rotate the right
 *
 *  @stack: Stack
 *
 *  @line_number: Line number
 *
 *  Return: Void
 */
void get_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		;
	}
	else
	{
		first = last = *stack;
		while (last->next)
		{
			last = last->next;
		}
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;
		*stack = last;
	}
}


/**
 * get_sub - function that subtracts the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
i * Description: 6. sub
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */
void get_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		first = *stack;
		second = first->next;
		second->n -= first->n;
		*stack = second;
		(*stack)->prev = NULL;
		free(first);
	}
}

/**
 * get_swap - function that swaps the top two elements on the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * Description: 3. swap
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */
void get_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	else if (*stack)
	{
		first = *stack;
		second = first->next;
		*stack = second;
		first->next = second->next;
		if (second->next != NULL)
		{
			second->next->prev = first;
		}
		second->prev = NULL;
		second->next = first;
		first->prev = second;
	}
}

