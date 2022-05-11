#include "monty.h"
int value;
void _push(stack_t **stack, unsigned int line_number)
{

	stack_t *new;
	
	line_number = line_number;
	value = atoi(strtok(NULL, " "));
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

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *nodo= *stack;

	line_number = line_number;
	while (nodo)
	{
		printf("%d\n", nodo->n);
		nodo = nodo->prev;
	}
}
