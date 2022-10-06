#include "monty.h"

void push(stack_t **top, unsigned int nline)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = oparg.store;
	if (*top)
	{
		(*top)->prev = new_node;
		new_node->next = *top;
		new_node->prev = NULL;
	}
	*top = new_node;
	return;
}
