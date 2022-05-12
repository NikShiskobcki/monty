#include "monty.h"

/**
 * _div - divides top elements
 * @stack: stack
 * @line_number: line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *aux1 = NULL, *aux2 = NULL;

	aux1 = *stack;
	if (aux1)
		aux2 = aux1->next;

	if (aux1 == NULL || aux2 == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	aux2->n = aux2->n / aux1->n;
	free(aux1);
	aux2->prev = NULL;
	*stack = aux2;

}

/**
 *_mul - multiplies top elements
 *@stack: stack
 *@line_number: line number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *aux1 = NULL, *aux2 = NULL;

	aux1 = *stack;
	if (aux1)
		aux2 = aux1->next;

	if (aux1 == NULL || aux2 == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	aux2->n = aux2->n * aux1->n;
	free(aux1);
	aux2->prev = NULL;
	*stack = aux2;
}


/**
 * _mod - modules top elements
 * @stack: stack
 * @line_number: line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *aux1 = NULL, *aux2 = NULL;

	aux1 = *stack;
	if (aux1)
		aux2 = aux1->next;

	if (aux1 == NULL || aux2 == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	aux2->n = aux2->n % aux1->n;
	free(aux1);
	aux2->prev = NULL;
	*stack = aux2;

}
