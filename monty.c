#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include "monty.h"

#define LINE 1000

int main(int argc, char **argv)
{
	FILE *bytecode_file;
	char bytecode[LINE];
	char *filename;
	int nline;
	char *opcode;
	long *oparg;
	
	nline = 1;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Read bytecode from file */
	filename = argv[1];
	bytecode_file = fopen(filename, "r");
	if (!bytecode_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	
	/* read bytecode while there still data to read */
	while (fgets(bytecode, LINE, bytecode_file))
	{
		
		/* checks if bytecode is valid */
		if (validate_bytecode(bytecode, &opcode, &oparg))
		{
			printf("Bycode is valid");
		}
		else
		{
			fprintf(stderr,"L%d: unknown instruction %s\n", nline, opcode);
			exit(EXIT_FAILURE);
		}
		++nline;
	}	
	
	return (0);
}
