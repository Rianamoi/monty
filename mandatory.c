#include "monty.h"
#include <ctype.h>

/**
 * get_pop - function that pops the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * Description: 2. pop
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */
void get_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *first;

	if ((*stack == NULL) || (stack == NULL))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	*stack = (*stack)->next;
	if (first->next)
	{
		first->next->prev = NULL;
	}
	free(first);
}

/**
 * get_pstr - function that prints ascii value of elements
 * @stack: pointer to head of the stack
 * @line_number: where the instruction appears
 * Description: 12. pstr
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */

void get_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node = *stack;

	(void)line_number;

	if ((stack == NULL) || (*stack == NULL))
	{
		printf("\n");
	}
	else
	{
		while (top_node != NULL)
		{
			if ((top_node->n > 0) && (isascii(top_node->n)))
			{
				printf("%c", top_node->n);
				top_node = top_node->next;
			}
			else
			{
				break;
			}
		}
		printf("\n");
	}
}

/**
 * get_push - function that pushes an element onto top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * @temp: Pointer to instruction
 * Description: 0. push, pall
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */
void get_push(stack_t **stack, unsigned int line_number, char *temp)
{

	stack_t *new_top;

	(void)line_number;

	if (temp == NULL || _isdigit(temp) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
		if (_isdigit(temp) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(file);
			get_free(*stack);
			exit(EXIT_FAILURE);
		}
	}
	new_top = malloc(sizeof(stack_t));
	if (new_top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	new_top->n = atoi(temp);
	new_top->next = NULL;
	new_top->prev = NULL;
	if (*stack)
	{
		new_top->next = *stack;
		(*stack)->prev = new_top;
		*stack = new_top;
	}
	*stack = new_top;
}


/**
 *  _isdigit - Finds if char is a digit or not
 *
 *  @str: Character passed in
 *
 *  Return: 1 for digit, 0 if not
 */

int _isdigit(char *str)
{

	int i = 0;


	if (str[i] == '-')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
		{
			return (1);
		}
		i++;
	}

	return (0);
}

