#include "monty.h"
int value;
/**
 * op_push - pushes  new noede
 * @stack: ouble pointer
 * @line_number: values
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void)line_number;

	new = nodenew(value);

	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
