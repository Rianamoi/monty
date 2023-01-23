#include "monty.h"

/**
 * read_file - read minty file, call instruction interpretor
 * @fd: monty file file descriptor
 * @stack: stack data structure
 *
 * Return: void
 */

void read_file(FILE *fd, _stack_t **stack)
{
	char *cmd = NULL, **cmds;
	unsigned int read, line = 1, eofno = -1;
	size_t len = 0;
	void (*instruction_t)(_stack_t **, unsigned int);

	while ((read = getline(&cmd, &len, fd)) != eofno)
	{
		cmds = tokens(cmd);
		if (!strcmp(*cmds, "exit"))
		{
			free(cmds);
			continue;
		}
		instruction_t = get_op(strip(&cmds[0]));
		if (!strcmp(strip(&cmds[0]), "push"))
		{
			if (!atoi(cmds[1]) && (strcmp(strip(&cmds[1]), "0") || !cmds[1]))
			{
				fprintf(stderr, "L%u: usage: push integer\n", line);
				exit(EXIT_FAILURE);
			}
			else if (!atoi(cmds[1]) || atoi(cmds[1]))
				instruction_t(&(*stack), atoi(cmds[1]));
		}
		else if (cmds[0] && instruction_t)
			instruction_t(&(*stack), line);
		if (!instruction_t && strcmp(cmds[0], "\n"))

		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line, cmds[0]);
			exit(EXIT_FAILURE);
		}
		line++;
		free(cmds);
	}
	if (cmd)
		free(cmd);
	exit(EXIT_SUCCESS);
}

/**
 * tokens - split command into tokens
 * @cmd: string to split
 *
 * Return: string array of tokens
 */

char **tokens(char *cmd)
{
	char *token, **cmds = malloc(2);
	int i = 0;

	token = strtok(cmd, " ");
	while (token)
	{
		cmds[i] = &*token;
		i++;
		if (*cmds[0] == '#')
		{
			cmds[0] = "exit";
			break;
		}

		if (i == 2)
			break;
		token = strtok(NULL, " ");
	}
	return (cmds);
}
