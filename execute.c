#include "monty.h"
/**
* execute - executes the opcode
* @stack: head  linked list - stack
* @cntr: line_cntr
* @file: poiner to monty file
* @contnt: line contnt
* Return: nothing
*/
int execute(char *contnt, stack_t **stack, unsigned int cntr, FILE *file)
{
	instruction_t opsst[] = {
				{"push", my_push}, {"pall", my_pall}, {"pint", my_pint},
				{"pop", my_pop},
				{"swap", my_swap},
				{"add", my_add},
				{"nop", my_nop},
				{"sub", my_sub},
				{"div", my_div},
				{"mul", my_mul},
				{"mod", my_mod},
				{"pchar", my_pchar},
				{"pstr", my_pstr},
				{"rotl", my_rotl},
				{"rotr", my_rotr},
				{"queue", my_queue},
				{"stack", my_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(contnt, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opsst[i].opcode && op)
	{
		if (strcmp(op, opsst[i].opcode) == 0)
		{	opsst[i].f(stack, cntr);
			return (0);
		}
		i++;
	}
	if (op && opsst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", cntr, op);
		fclose(file);
		free(contnt);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
