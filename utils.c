#include "monty.h"

/**
 * error_exit - frees the stack and exits program
 *
 * @stack: pointer to the head of stack
 */
void error_exit(c_stack_t **stack)
{
	if (*stack)
		free_dlistint(*stack);
	exit(EXIT_FAILURE);
}
