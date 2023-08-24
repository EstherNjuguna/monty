#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Pointer to the stack's top
 */
void pop(stack_t **stack)
{
	stack_t *temp;
	if (*stack == NULL)
	{
		fprintf(stderr, "Cannot pop from an empty stack\n");
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
