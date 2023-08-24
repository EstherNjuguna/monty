#include "monty.h"

/**
 * op_add - Adds the top two elements of the stack.
 * @stack: Pointer to the stack's top
 * @line_number: Line number in the Monty bytecode file
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_r(stack);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	pop(stack);
	(*stack)->n = sum;
}
