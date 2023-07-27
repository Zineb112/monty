#include "monty.h"
/**
 * my_pop - prints the_top
 * @head_stk: stack head_stk
 * @cntr: line_nbr
 * Return: nothing
*/
void my_pop(stack_t **head_stk, unsigned int cntr)
{
	stack_t *h;

	if (*head_stk == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", cntr);
		fclose(bus.file);
		free(bus.contnt);
		free_stack(*head_stk);
		exit(EXIT_FAILURE);
	}
	h = *head_stk;
	*head_stk = h->next;
	free(h);
}
