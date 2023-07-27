#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - monty code_interpreter
* @argc: nbr of arg
* @argv: monty file loction
* Return: 0 if  success
*/
int main(int argc, char *argv[])
{
	char *contnt;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int cntr = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		contnt = NULL;
		read_line = getline(&contnt, &size, file);
		bus.contnt = contnt;
		cntr++;
		if (read_line > 0)
		{
			execute(contnt, &stack, cntr, file);
		}
		free(contnt);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
