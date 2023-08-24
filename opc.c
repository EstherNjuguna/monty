#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * execute_opcode - Executes the given opcode with its arguments.
 * @opcode: The opcode to execute
 * @arg: The argument associated with the opcode (can be NULL)
 * @stack: Pointer to the stack
 * @line_number: Current line number in the Monty bytecode file
 * Return: 0 on success, -1 on failure
 */
int execute_opcode(const char *opcode, const char *arg, stack_t **stack, unsigned int line_number)
{

	instruction_t opcodes[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		/* Add more opcodes as needed */
		{NULL, NULL}
	};
	int i;

	(void) arg;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			if (opcodes[i].f != NULL)
			{
				opcodes[i].f(stack, line_number);
				return (0);
			}
			else
			{
				fprintf(stderr, "Error: Function for opcode '%s' is NULL\n", opcode);
				return (-1);
			}
		}
		i++;
	}

	fprintf(stderr, "Error: Unknown instruction '%s' at line %u\n", opcode, line_number);
	return (-1);
}
