#include "monty.h"

#define LINE 1000

int main(int argc, char **argv)
{
	FILE *bytecode_file;
	char *bytecode;
	char *filename;
	int nline;
	size_t line_s;

	bytecode = NULL;
	line_s = 0;
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
	while (getline(&bytecode, &line_s, bytecode_file) != -1)
	{
		validate_bytecode(bytecode, nline);
		++nline;
	}

	free(bytecode);
 	fclose(bytecode_file);	
	exit(EXIT_SUCCESS);
}
