#include "monty.h"

/**
 * validate_bytecode - Takes a bytecode and check if it valid
 * @bytecode: bytecode to validate
 * @opcode: a pointer to char opcode value
 * @oparg: a pointer to a int oparg value
 * Return: 0 if not valid, 1 if valid
 */
void validate_bytecode(char *bytecode, unsigned int nline)
{
	char *token1;
	char *token2;
	char *token3;
	char delim[] = " ";
	char *opargerr;
	long n;


	/* tokenize byte code into token */
	token1 = token2 = token3 = NULL;
	token1 = strtok(bytecode, delim);
	if (token1)
	{
		token2 = strtok(NULL, delim);
		token3 = strtok(NULL, delim);
	}
	else
		exit(0);

	/* parse token */
	if (strcmp(token1, "push") == 0)
	{
		if (token3 == NULL)
		{
			errno = 0;
			n = strtol(token2, &opargerr, 10);
			if (errno != 0)
			{
				fprintf(stderr,"L%d: usage: push integer\n", nline);
				exit(EXIT_FAILURE);
			}
			/* execute instruction */
			oparg.store = n;
			ex_opcode(token1, nline);
		}
	}
	exit(0);
}
