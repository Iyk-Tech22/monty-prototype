#include "monty.h"

/* opcode instruction */
void ex_opcode(char *opcode, unsigned int nline)
{
	int i;
	stack_t *stack;
	instruction_t op_s[2] = {
								{"push", push},
								{NULL, NULL}
					   	    };

	stack = NULL;
	i = 0;
	while (op_s[i].opcode)
	{
		if (strcmp(opcode, op_s[i].opcode) == 0)
		{	
			printf("Execut...\n");
			op_s[i].f(&stack, nline);
			printf("stack-tp:%d\n", stack->n);
			return;
		}
		++i;
	}

	fprintf(stderr,"L%d: unknown instruction %s", nline, opcode);
	exit(EXIT_FAILURE);
}
