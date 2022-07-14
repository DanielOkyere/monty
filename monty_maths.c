#include "monty.h"
/**
 * _add - adds to top of stack
 *
 * @stack: pointer to linked list stack
 * @line_num: line number which opcode occurs
 */
void _add(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_num);
		error_exit(stack);
	}
	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_num);
}
