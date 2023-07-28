#include "monty.h"

/**
 * my_push - add_node to stack.
 * @head_stk: stack_head_stk.
 * @cntr: line_nbr.
*/
void my_push(stack_t **head_stk, unsigned int cntr)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", cntr);
			fclose(bus.file);
			free(bus.contnt);
			free_stack(*head_stk);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", cntr);
		fclose(bus.file);
		free(bus.contnt);
		free_stack(*head_stk);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.flg_lifi == 0)
		add_nod(head_stk, n);
	else
		add_qu(head_stk, n);
}


/**
 * my_pall - prints stack
 * @head_stk: stack head_stk
 * @cntr: un_used
 * Return: nothing
*/
void my_pall(stack_t **head_stk, unsigned int cntr)
{
	stack_t *h;
	(void)cntr;

	h = *head_stk;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
