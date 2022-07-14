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
} stack_t;

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/* ------ monty-functs ------- */
void read_file(char *filename, stack_t **stack);
void free_dlistint(stack_t *head);
typedef void (*inst_func)(stack_t **stack, unsigned int line_number);
inst_func get_op_func(char *str);
char *parse_line(char *line);
/* ------- util functs ------- */
void error_exit(stack_t **stack);
int isnum(char *str);
/* ------- list functs ------- */
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int indx);
/* ------- output functs ------- */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_num);
void _pop(stack_t **stack, unsigned int line_num);
void _swap(stack_t **stack, unsigned int line_num);
void _nop(stack_t **stack, unsigned int line_num);
void _stack(stack_t **stack, unsigned int line_num);
void _queue(stack_t **stack, unsigned int line_num);
void _add(stack_t **stack, unsigned int line_num);
#endif
