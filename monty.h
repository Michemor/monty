#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 1024
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void read_line(char *, size_t, unsigned int);
void push(stack_t **stack, unsigned int line_number);
/*void free_list(char **some_data);*/
void check_push(char **, unsigned int);
void command_direction(char *, unsigned int);
void push_stack(stack_t **, unsigned int);
stack_t *create_node(int);
void pall_stack(stack_t **, unsigned int);
#endif /* MONTY_H */
