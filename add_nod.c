#include "monty.h"

/**
 * add_nod - add  node to the head_stk
 * @head_stk: head  stack
 * @n: new_value
 * Return: nothing
*/
void add_nod(stack_t **head_stk, int n)
{

	stack_t *new_node, *auxx;

	auxx = *head_stk;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (auxx)
		auxx->prev = new_node;
	new_node->n = n;
	new_node->next = *head_stk;
	new_node->prev = NULL;
	*head_stk = new_node;
}
