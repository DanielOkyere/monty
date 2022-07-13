#include "monty.h"

/**
 * _push - push element to stack
 *
 * @stack: head of stack
 * @line_number: number of line opcode occurs on
 */
void _push(c_stack_t **stack, unsigned int line_number)
{
	c_stack_t *new;
	char *arg;
	int push_arg;

	push_arg = 0;
	new = malloc(sizeof(c_stack_t));
	if (!new)
	{
		printf("Error: malloc failed\n");
		error_exit(stack);
	}
	arg = strtok(NULL, "\n ");
	if (isnum(arg) == 1 && arg != NULL)
	{
		push_arg = atoi(arg);
	}
	else
	{
		printf("L%d: usage: push integer\n", line_number);
		error_exit(stack);
	}

	if (sq_flag == 1)
	{
		add_dnodeint_end(stack, push_arg);
	}

	if (sq_flag == 0)
	{
		add_dnodeint(stack, push_arg);
	}
}

/**
 * _pall - prints all functions
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs
 */
void _pall(c_stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	c_stack_t *runner;

	runner = *stack;
	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}
