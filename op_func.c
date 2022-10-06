#include "monty.h"

void push(stack_t **top, unsigned int nline)
{
	stack_t *new_node;
	if (!isdigit(oparg.store))
	{
		fprintf(stderr,"L%u: usage: push integer, push", nline);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = oparg.store;
	new_node->prev = NULL;
	new_node->next = NULL;
	*top = new_node;
	exit(EXIT_SUCCESS);
}
