#include "monty.h"
/**
 * my_mod - computes the rest of the division
 * @head_stk: stack_head_stk
 * @cntr: line_nbr
 * Return: nothing
*/
void my_mod(stack_t **head_stk, unsigned int cntr)
{
	stack_t *he;
	int lent = 0, auxx;

	he = *head_stk;
	while (he)
	{
		he = he->next;
		lent++;
	}
	if (lent < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", cntr);
		fclose(bus.file);
		free(bus.contnt);
		free_stack(*head_stk);
		exit(EXIT_FAILURE);
	}
	he = *head_stk;
	if (he->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", cntr);
		fclose(bus.file);
		free(bus.contnt);
		free_stack(*head_stk);
		exit(EXIT_FAILURE);
	}
	auxx = he->next->n % he->n;
	he->next->n = auxx;
	*head_stk = he->next;
	free(he);
}
