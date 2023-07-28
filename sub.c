#include "monty.h"

/**
  *my_sub- susstration of an element
  *@head_stk: stack_head_stk
  *@cntr: line_nbr
  *Return: nothing
 */
void my_sub(stack_t **head_stk, unsigned int cntr)
{
	stack_t *auxx;
	int suss, nodes;

	auxx = *head_stk;
	for (nodes = 0; auxx != NULL; nodes++)
		auxx = auxx->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", cntr);
		fclose(bus.file);
		free(bus.contnt);
		free_stack(*head_stk);
		exit(EXIT_FAILURE);
	}
	auxx = *head_stk;
	suss = auxx->next->n - auxx->n;
	auxx->next->n = suss;
	*head_stk = auxx->next;
	free(auxx);
}
