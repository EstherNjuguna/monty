#include "monty.h"

/**
 * op_add - Adds the top two elements of the stack.
 * @stack: Pointer to the stack's top
 * @line_number: Line number in the Monty bytecode file
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;

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
/**
 * _isdigit - checks if it is a digit
 * Return: 0 or 1
 * @c: Value
 **/

int _isdigit(char *c)
{
	char *tmp = c;

	if (c == NULL)
		return (0);
	if (*tmp == '-')
		tmp++;

	for (; *tmp != '\0'; tmp++)
	{
		if ((*tmp < '0' || *tmp > '9'))
		{
			return (0);
		}
	}
	return (1);
}
