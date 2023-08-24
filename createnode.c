#include "monty.h"
/**
 * nodenew - create new node
 * @n: value of node
 * Return: newnode
 */
stack_t *nodenew(int n)
{
	stack_t *newer = NULL;

	newer = malloc(sizeof(stack_t));
	if (newer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newer->n = n;
	newer->next = NULL;
	newer->prev = NULL;

	return (newer);
}
