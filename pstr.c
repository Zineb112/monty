#include "monty.h"
/**
 * my_pstr - prints the string at the top of stack
* @head_stk: stack_head_stk
 * @cntr: line_nbr
 * Return: nothing
*/
void my_pstr(stack_t **head_stk, unsigned int cntr)
{
	stack_t *h;
	(void)cntr;

	h = *head_stk;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
