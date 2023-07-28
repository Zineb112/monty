#include "monty.h"
/**
  *my_rotr- rotates stack to the bottom
  *@head_stk: stack_head_stk
  *@cntr: line_nbr
  *Return: nothing
 */
void my_rotr(stack_t **head_stk, __attribute__((unused)) unsigned int cntr)
{
	stack_t *copy;

	copy = *head_stk;
	if (*head_stk == NULL || (*head_stk)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head_stk;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head_stk)->prev = copy;
	(*head_stk) = copy;
}

