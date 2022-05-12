#include "monty.h"
int value;
/**
 *_push - pushes
 *@stack: stack
 *@line_number: line number
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *data;
	stack_t *new, *aux;

	line_number = line_number;
	data = strtok(NULL, " \n\t");
	if (data != NULL && is_number(data) == 0)
		value = atoi(data);
	else
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		if ((*stack) != NULL)
		{
			while (*stack)
			{
				aux = (*stack);
				(*stack) = (*stack)->next;
				free(aux);
			}
		}
		free(*stack);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 *_pall- prints all
 *@stack: stack
 *@line_number: line number
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *nodo = *stack;

	line_number = line_number;
	while (nodo)
	{
		printf("%d\n", nodo->n);
		nodo = nodo->next;
	}
}

/**
 *_pint- prints first item
 *@stack: stack
 *@line_number: line number
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		frStack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}
