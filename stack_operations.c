#include "monty.h"
extern int num;
/**
 * push - creates a linked list and push items to it
 * @stack: pointer to an item on the stack
 * @line_number: line number
 */
void push_stack(stack_t **stack, unsigned int line_no)
{	
	stack_t *new_node;
	(void)line_no;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed");
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = NULL;

	if(*stack)
	{
	new_node->next = *stack;
	(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * pall_stack - prints contents inside a stack
 * @stack: pointer to topmost item on the stack
 * @line_no: line of the command
 */
void pall_stack(stack_t **stack, unsigned int line_no)
{
	stack_t *temp;
	(void)line_no;

	temp = *stack;

	while (temp)
	{
	fprintf(stdout, "%d\n",temp->n);
	temp = temp->next;
	}
}

