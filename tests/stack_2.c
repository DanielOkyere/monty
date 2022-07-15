#include "monty.h"

/**
 * _nop - does nothing
 * @stack: pointer to top of stack
 * @line_num: index of current line
 */
void _nop(__attribute__ ((unused))stack_t **stack,
	__attribute__ ((unused))unsigned int line_num)
{
	;
}

/**
 * _stack - sets sq_flag to stack
 * @stack: pointer to stack list
 * @line_num: line opcode occurs on
 */
void _stack(__attribute__ ((unused))stack_t **stack,
	__attribute__ ((unused))unsigned int line_num)
{
	sq_flag = 0;
}

/**
 * _queue - sets sq_flag to queue
 * @stack: pointer to stack list
 * @line_num: line opcode occurs on
 */
void _queue(__attribute__ ((unused))stack_t **stack,
	__attribute__ ((unused))unsigned int line_num)
{
	sq_flag = 1;
}
