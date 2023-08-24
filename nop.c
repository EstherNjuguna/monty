#include "monty.h"

/**
 * op_nop - Doesn't do anything.
 * @stack: Pointer to the stack's top
 * @line_number: Line number in the Monty bytecode file
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
