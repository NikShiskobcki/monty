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

	if (aux == NULL || aux->next == NULL)
	{
		fprintf(stderr, "Liu: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = aux->next->n;
	aux->next->n = aux->n;
	aux->n = i;
}

/**
 * _add - adds two top elements
 * @stack: stack
 * @line_number: line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux1 = NULL, *aux2 = NULL;

	aux1 = *stack;
	if(aux1)
		aux2 = aux1->next;

	if (aux1 == NULL || aux2 == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	aux2->n = aux2->n + aux1->n;
	free(aux1);
	aux2->prev = NULL;
	*stack = aux2;
}

/**
 *_nop - does nothing
 *@stack: stack
 *@line_number: line number
*/
void _nop(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}
