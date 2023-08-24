#include "monty.h"

/**
 * op_pall - Pushes an element to the stack.
 * @stack: Pointer to the stack's top
 * @line_number: Line number in the Monty bytecode file
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h = NULL;
	(void)line_number;

	h = *stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
