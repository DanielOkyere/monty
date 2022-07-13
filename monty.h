#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

extern int sq_flag;
/*------ Data Structures ------*/

/**
 * struct stack_s - doubly linked list representation of a stack
 * (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or qeuue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 *
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} c_stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 *
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(c_stack_t **stack, unsigned int line_number);
} instruction_t;
void read_file(char *filename, c_stack_t **stack);
void free_dlistint(c_stack_t *head);
typedef void (*inst_func)(c_stack_t **stack, unsigned int line_number);
inst_func get_op_func(char *str);
char *parse_line(char *line);
void error_exit(c_stack_t **stack);
#endif
