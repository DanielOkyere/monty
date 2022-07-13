#include "monty.h"
/**
 * add_dnodeint - adds node the front of linked list
 *
 * @head: pointer to first node
 * @n: data for node
 * Return: pointer to first node
 */
c_stack_t *add_dnodeint(c_stack_t **head, const int n)
{
	c_stack_t *new;

	new = malloc(sizeof(c_stack_t));
	if (new == NULL)
		return (NULL);

	if (*head == NULL)
	{
		new->n = n;
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (*head);
	}

	(*head)->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);
}

/**
 * add_dnodeint_end - adds node toend of list
 *
 * @head: pointer to first node
 * @n: data in the node
 * Return: pointer to first node
 */
c_stack_t *add_dnodeint_end(c_stack_t **head, const int n)
{
	c_stack_t *tmp = *head;
	c_stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	if (*head == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
	return (new);
}
