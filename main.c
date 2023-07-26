#include "monty.h"

/**
 * main - check code.
 * @argc: command line arguments.
 * @argv: command line arguments string array.
 * Return: 0 on success, non-zero on failure.
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    char opcode[100];
    int value;
    unsigned int line_number = 1;

    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };

    while (fscanf(file, "%s", opcode) != EOF)
    {
        if (strcmp(opcode, "push") == 0)
        {
            if (fscanf(file, "%d", &value) != 1)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file);
                free_stack(stack);
                return (EXIT_FAILURE);
            }
            push(&stack, value, line_number);
        }
        else
        {
            int i = 0;
            while (instructions[i].opcode != NULL)
            {
                if (strcmp(opcode, instructions[i].opcode) == 0)
                {
                    instructions[i].f(&stack, line_number);
                    break;
                }
                i++;
            }
            if (instructions[i].opcode == NULL)
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                fclose(file);
                free_stack(stack);
                return (EXIT_FAILURE);
            }
        }
        line_number++;
    }

    fclose(file);
