#include "monty.h"
/**
 * read_file - reads monty bytecode and runs commands
 * @filename: path to file
 * @stack: pointer to the top stack
 *
 */
void read_file(char *filename, stack_t **stack)
{
	char *buf = NULL, *line;
	size_t i = 0;
	int check, read, lc = 1;
	FILE *fp = fopen(filename, "r");
	inst_func s;

	if (fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		error_exit(stack);
	}
	while ((read = getline(&buf, &i, fp)) != -1)
	{
		line = parse_line(buf);
		if (line == NULL || line[0] == '#')
		{
			lc++;
			continue;
		}
		s = get_op_func(line);
		if (s == NULL)
		{
			dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", lc, line);
		}
		s(stack, lc);
		lc++;
	}
	free(buf);
	check = fclose(fp);
	if (check == -1)
		exit(-1);
}

/**
 * free_dlistint - free a list
 * @head: pointer to first node
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}

}

/**
 * get_op_func - fetches the right function when compared with
 * op_code
 * @str: the op_code
 *
 * Return: returns a function or NULL
 */
inst_func get_op_func(char *str)
{
	int i, codes = 9;

	instruction_t inx[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"nop", _nop},
		{"add", _add},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	for (i = 0; i < codes; i++)
	{
		if (strcmp(inx[i].opcode, str) == 0)
			return (inx[i].f);
	}
	return (NULL);
}

/**
 * parse_line - parses lines in opcode and arguments
 * @line: line to be parse
 * Return: returns opcode in string or null on failure
 */
char *parse_line(char *line)
{
	char *op_code;

	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	return (op_code);
}
