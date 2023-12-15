#include "monty.h"
/**
 * command_direction - calls command according to string pointed to
 * by cmd pointer
 * @cmd: pointer to command
 * @num: number to be parsed with command
 */
void command_direction(char *cmd, unsigned int line_no)
{
	stack_t *head;
	int i;

	instruction_t op[] = {
		{"push", push_stack},
		{"pall", pall_stack},
		{NULL, NULL}
	};

	i = 0;
	while (i != 2)
	{
	if (strcmp(cmd, op[i].opcode) == 0)
	{
	op[i].f(&head, line_no);
	break;
	}
	i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_no, cmd);
	exit(EXIT_FAILURE);
}
