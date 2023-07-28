#include "monty.h"
/**
 * my_queue - prints the_top
 * @head_stk: stack_head_stk
 * @cntr: line_nbr
 * Return: nothing
*/
void my_queue(stack_t **head_stk, unsigned int cntr)
{
	(void)head_stk;
	(void)cntr;
	bus.flg_lifi = 1;
}

/**
 * add_qu - add a node to the stack tail.
 * @head_stk: the satck head.
 * @n: new int value.
 */
void add_qu(stack_t **head_stk, int n)
{
	stack_t *new_node, *auxx;

	auxx = *head_stk;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (auxx)
	{
		while (auxx->next)
			auxx = auxx->next;
	}
	if (!auxx)
	{
		*head_stk = new_node;
		new_node->prev = NULL;
	}
	else
	{
		auxx->next = new_node;
		new_node->prev = auxx;
	}
}
