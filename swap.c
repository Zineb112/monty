#include "monty.h"
/**
 * my_swap - adds the top of stack.
 * @head_stk: stack_head_stk
 * @cntr: line_nbr
 * Return: nothing
*/
void my_swap(stack_t **head_stk, unsigned int cntr)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", cntr);
		fclose(bus.file);
		free(bus.contnt);
		free_stack(*head_stk);
		exit(EXIT_FAILURE);
	}
	h = *head_stk;
	auxx = h->n;
	h->n = h->next->n;
	h->next->n = auxx;
}
