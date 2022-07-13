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

/**
 * isnum - checks a sting if its a number
 * @str: string passed to function
 * Return: 1 if a number, 0 if otherwise
 */
int isnum(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);

	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
