#include "monty.h"

/**
 * push - add elements to the stack.
 * @stack: double pointr.
 * @value: int.
 * @line_number: unsigned int.
 * Return: new elemznt address.
 */
void push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - print elements to the stack.
 * @stack: double pointr.
 * @line_number: unsigned int.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
