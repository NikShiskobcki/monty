#include "monty.h"

/**
 * _swap - swaps first and second elemensts of the stack
 *@stack: stack
 *@line_number: line number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *aux = *stack;

	if (aux == NULL || aux->prev == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = aux->prev->n;
	aux->prev->n = aux->n;
	aux->n = i;
}
