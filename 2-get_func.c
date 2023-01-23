#include "monty.h"
#include "lists.h"

/**
 * get_func - selects the right function 
 * @parsed: line from the bytecode file passed to main
 *
 * Return: pointer to the selected function, or NULL on failure
 */
void (*get_func(char **parsed))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", push_handler},
		{"pall", pall_handler},
		{"pint", pint_handler},
		{"pop", pop_handler},
		{"swap", swap_handler},
		{"add", add_handler},
		{"nop", nop_handler},
		{"sub", sub_handler},
		{"div", div_handler},
		{"mul", mul_handler},
		{"mod", mod_handler},
		{"pchar", pchar_handler},
		{"pstr", pstr_handler},
		{"rotl", rotl_handler},
		{"rotr", rotr_handler},
		{"stack", stack_handler},
		{"queue", queue_handler},
		{NULL, NULL}
	};

	int codes = 17, i;

	for (i = 0; i < codes; i++)
	{
		if (strcmp(func_arr[i].opcode, parsed[0]) == 0)
		{
			return (func_arr[i].f);
		}
	}
	return (NULL);
}

/**
 * push_handler - handles the push instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void push_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int num = 0, i;

	if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	for (i = 0; data.words[1][i]; i++)
	{
		if (isalpha(data.words[1][i]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
			free_all(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(data.words[1]);

	if (data.qflag == 0)
		new = add_dnodeint(stack, num);
	else if (data.qflag == 1)
		new = add_dnodeint_end(stack, num);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall_handler - handles the pall instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pall_handler(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		print_dlistint(*stack);
}

/**
 * pint_handler - handles the pint instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */

void pint_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!head)
	{
		dprintf(STDERR_FILENO, PINT_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}

/**
 * pop_handler - handles the pop instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pop_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		dprintf(STDERR_FILENO, POP_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_at_index(stack, 0);
}

/**
 * swap_handler - handles the swap instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void swap_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *node = NULL;
	int num;

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SWAP_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	temp = get_dnodeint_at_index(*stack, 0);
	num = temp->n;
	delete_dnodeint_at_index(stack, 0);
	node = insert_dnodeint_at_index(stack, 1, num);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * add_handler - handles the add instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void add_handler(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, ADD_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	sum = node_0->n + node_1->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, sum);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop_handler - handles the nop instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void nop_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub_handler - handles the sub instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */

void sub_handler(stack_t **stack, unsigned int line_number)
{
	int sub = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SUB_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	sub = node_1->n - node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, sub);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * div_handler - handles the div instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void div_handler(stack_t **stack, unsigned int line_number)
{
	int div = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, DIV_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	div = node_1->n / node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, div);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul_handler - handles the mul instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void mul_handler(stack_t **stack, unsigned int line_number)
{
	int mul = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MUL_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	mul = node_1->n * node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, mul);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod_handler - handles the mod instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void mod_handler(stack_t **stack, unsigned int line_number)
{
	int mod = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MOD_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	mod = node_1->n % node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, mod);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * rotl_handler - handles the rotl instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */

void rotl_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num  = 0;

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = get_dnodeint_at_index(*stack, 0);
	num = temp->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint_end(stack, num);
}

/**
 * rotr_handler - handles the rotr instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void rotr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num = 0, len = dlistint_len(*stack);

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = get_dnodeint_at_index(*stack, len - 1);
	num = temp->n;
	delete_dnodeint_at_index(stack, len - 1);
	add_dnodeint(stack, num);
}

/**
 * stack_handler - handles the stack instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void stack_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 0;
}

/**
 * queue_handler - handles the queue instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void queue_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 1;
}

/*
 * File: int_to_string.c
 * Auth: Bennett Dixon
 */

#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size);

/**
 * get_int - gets a character pointer to new string containing int
 * @num: number to convert to string
 *
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++; /* negative sign */
	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - gets the absolute value of an integer
 * @i: integer to get absolute value of
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - gets length of buffer needed for an unsigned int
 * @num: number to get length needed for
 * @base: base of number representation used by buffer
 *
 * Return: integer containing length of buffer needed (doesn't contain null bt)
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1; /* all numbers contain atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - fills buffer with correct numbers up to base 36
 * @num: number to convert to string given base
 * @base: base of number used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 *
 * Return: always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* return lowercase ascii val representation */
			buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
