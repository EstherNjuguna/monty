#include "monty.h"

/**
 * free_resources - Frees allocated resources.
 * @stack: Pointer to the stack's top
 */
void free_resources(stack_t **stack)
{
	while (*stack != NULL)
	{
		stack_t *temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
