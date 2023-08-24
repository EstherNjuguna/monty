#include "monty.h"

/**
 * op_pint - Prints the value at the top of the stack.
 * @stack: Pointer to the stack's top
 * @line_number: Line number in the Monty bytecode file
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_r(stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
