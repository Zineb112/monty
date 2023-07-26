#include "monty.h"

/**
 * free_stack - free all the allocated memory for the stack.
 * @stack: pointer to the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		stack_t *temp = current;

		current = current->next;
		free(temp);
	}
}
