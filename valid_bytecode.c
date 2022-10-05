#include "monty.h"
#include <errno.h>
#include <string.h>
#include <stdlib.h>

/**
 * validate_bytecode - Takes a bytecode and check if it valid
 * @bytecode: bytecode to validate
 * @opcode: a pointer to char opcode value
 * @oparg: a pointer to a int oparg value
 * Return: 0 if not valid, 1 if valid
 */
int validate_bytecode(char *bytecode, char **opcode, long *oparg)
{
	char *token1;
	char *token2;
	char *token3;
	char delim[] = " ";
	long oparg_int;
	char *opargerr;


	/* tokenize byte code into token */
	token1 = token2 = token3 = NULL;
	token1 = strtok(bytecode, delim);
	if (token1)
	{
		token2 = strtok(NULL, delim);
		token3 = strtok(NULL, delim);
	}
	
	/* parse token */

	/* push opcode */
	if (strcmp(token1, "push") == 0)
	{
		if (token3 == NULL)
		{
			errno = 0;
			oparg_int = strtol(token2, &opargerr, 10);
			if (errno != 0)
			{
				*opcode = token1;
				*oparg = -1;
				return (0);
			}
			*opcode = token1;
			*oparg = oparg_int;
			return (1);
		}
		else
		{
			*opcode = token1;
			*oparg = -1;
			return (0);
		}
	}
	else
	{
		*opcode = token1;
		*oparg = -1;
		return (0);
	}
}

