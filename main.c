#include "monty.h"

/**
 * main - Program entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success
 */

int main(int ac, __attribute__((unused)) char **av)
{
	FILE *fd;
	_stack_t *stack = malloc(sizeof(_stack_t));

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	read_file(fd, &stack);
	fclose(fd);
	free_stack_t(stack);
	return (0);
}
