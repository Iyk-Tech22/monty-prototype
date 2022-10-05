#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "monty.h"

#define LINE 1000

int main(int argc, char **argv)
{
	FILE *bytecode_file;
	char bytecode[LINE];
	char *filename;

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
	
	/* Execute bytecode */
	while (fgets(bytecode, LINE, bytecode_file))
	{
		
	}
	
	return (0);
}




