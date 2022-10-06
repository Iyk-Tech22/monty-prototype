#include "monty.h"

#define LINE 1000

int main(int argc, char **argv)
{
	FILE *bytecode_file;
	char bytecode[LINE];
	char *filename;
	int nline;
	
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
		validate_bytecode(bytecode, nline);
		++nline;
	}	
	
	return (0);
}
