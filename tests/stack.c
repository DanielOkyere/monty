#include "monty.h"

/**
 * _push - push element to stack
 *
 * @stack: head of stack
 * @line_number: number of line opcode occurs on
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *arg;
	int push_arg;

	push_arg = 0;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		error_exit(stack);
	}
	arg = strtok(NULL, "\n ");
	if (isnum(arg) == 1 && arg != NULL)
	{
		push_arg = atoi(arg);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
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
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	while (runner != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * _pint - print int a top of stack
 *
 * @stack: pointer to linked list stack
 * @line_num: number of line opcode occurs on
 */
void _pint(stack_t **stack, unsigned int line_num)
{
	stack_t *runner;

	runner = *stack;
	if (runner == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_num);
		error_exit(stack);
	}
	dprintf(STDOUT_FILENO, "%d\n", runner->n);
}

/**
 * _pop - delete item at top of stack
 *
 * @stack: pointer to linked list stack
 * @line_num: number of line opcode occurs on
 */
void _pop(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_num);
		error_exit(stack);
	}
	delete_dnodeint_at_index(stack, 0);
}

/**
 * _swap - swap top of stack and second top of stack
 *
 * @stack: pointer to linked list stack
 * @line_num: line number for which opcode occurs on
 */
void _swap(stack_t **stack, unsigned int line_num)
{
	stack_t *runner;
	int tmp;

	runner = *stack;
	if (runner == NULL || runner->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_num);
		error_exit(stack);
	}
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}
