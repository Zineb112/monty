#include "monty.h"

/**
 * my_add - adds the top elements of stack.
 * @head_stk: stack head_stk
 * @cntr: line_nbr
 * Return: nothing
*/
void my_add(stack_t **head_stk, unsigned int cntr)
{
	stack_t *h;
	int len = 0, auxx;

	h = *head_stk;
	while (h)
	{
		h = h->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", cntr);
		fclose(bus.file);
		free(bus.contnt);
		free_stack(*head_stk);
		exit(EXIT_FAILURE);
	}

	h = *head_stk;
	auxx = h->n + h->next->n;
	h->next->n = auxx;
	*head_stk = h->next;
	free(h);
}
