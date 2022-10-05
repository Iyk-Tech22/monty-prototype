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
	char *token1, *token2, *token3;
	/*char  *v_bytecode[3] = {"push", "pop", "pall"};*/
	char delim[] = " ";
	int nline;
	long oparg;
	char *opargerr;
	
	token1 = NULL;
	token2 = NULL;
	token3 = NULL;
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
		token1 = strtok(bytecode, delim);
		if (token1)
		{
			token2 = strtok(NULL, delim);
			token3 = strtok(NULL, delim);
		}
		/* checks if bytecode is valid */
		if (strcmp(token1, "push") == 0)
		{
				if (token3 == NULL)
				{
					errno = 0;
					oparg = strtol(token2, &opargerr, 10);
					if (errno != 0)
					{
						fprintf(stderr,"L%d: unknown instruction1 %s\n", nline, token1);
						exit(EXIT_FAILURE);
					}
					printf("L%d: %s %ld\n", nline, token1, oparg); 
				}
				else
				{
					fprintf(stderr,"L%d: unknown instruction2 %s\n", nline, token1);
					exit(EXIT_FAILURE);
				}
		}
		else
		{
				fprintf(stderr,"L%d: unknown instruction3 %s\n", nline, token1);
				exit(EXIT_FAILURE);
		}
		++nline;
	}	
	
	return (0);
}
