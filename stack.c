#include "monty.h"

/**
 * free_stack_t - free stack memory
 * @head: head of stack
 *
 * Return: void
 */

void free_stack_t(_stack_t *head)
{
	_stack_t *node, *next_node;

	if (head)
	{
		node = head;
		next_node = head->next;
		while (next_node)
		{
			free(node);
			node = next_node;
			next_node = next_node->next;
		}
		free(node);
	}
}

/**
 * strip - remove trailing new line character
 * @str: string to strip
 *
 * Return: stripped string
 */

char *strip(char **str)
{
	char *bc = malloc(sizeof(strlen(*str)));

	bc = strtok(*str, "\n");
	if (bc)
		*str = bc;
	return (*str);
}

/**
 * isint - determine if val is num
 * node: node from stack ds
 *
 * Return: 1 if is int, else 0
 */

int isint(_stack_t *node)
{
	if (node->n || node->n == 0)
		return (1);
	return (0);
}

/**
 * get_op - retrieve stack function
 * @opcode: function name
 *
 * Return: valid stack function, else NULL
 */

void (*get_op(char *opcode))(_stack_t **, unsigned int line)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}};
	int i = 0;

	while (ops[i].opcode)
	{
		if (!strcmp(opcode, ops[i].opcode))
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
