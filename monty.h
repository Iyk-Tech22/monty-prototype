#ifndef MAIN_H
#define MAIN_H

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

#endif
