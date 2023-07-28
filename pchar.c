#include "monty.h"
/**
 * my_pchar - prints the char at the top of stack,
 * followed by a new line
 * @head_stk: stack_head_stk
 * @cntr: line_nbr
 * Return: nothing
*/
void my_pchar(stack_t **head_stk, unsigned int cntr)
{
	stack_t *h;

	h = *head_stk;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", cntr);
		fclose(bus.file);
		free(bus.contnt);
		free_stack(*head_stk);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", cntr);
		fclose(bus.file);
		free(bus.contnt);
		free_stack(*head_stk);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
