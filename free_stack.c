#include "monty.h"

/**
* free_stack - frees a doubly linked list
* @head_stk: head  of stack
*/
void free_stack(stack_t *head_stk)
{
	stack_t *auxx;

	auxx = head_stk;
	while (head_stk)
	{
		auxx = head_stk->next;
		free(head_stk);
		head_stk = auxx;
	}
}
