#ifndef MAIN_H
#define MAIN_H

/* required headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

/**
 * Struct stack_s - Stack Data Structure use to store
 * @n: Integer
 * @prev: Point to prev node
 * @next: Point to next node
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instructon_s - opcode function
 * @opcode: name of instruction
 * @f: function for opcode instruction
 */
typedef struct instruction_s
{
	char *opcode;
	void (* f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct oparg_s - oparg data
 * @store
 */
typedef struct oparg_s
{
	long store;
} oparg_t;
extern oparg_t oparg;
oparg_t oparg;

/* prototype function */
void validate_bytecode(char *bytecode, unsigned int nline);
void ex_opcode(char *opcode, unsigned int nline);
void push(stack_t **top, unsigned int nline);


#endif
