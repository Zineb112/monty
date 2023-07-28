#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - variables -args, file, line contnt
 * @arg: value
 * @file: pointer to monty file
 * @contnt: line contnt
 * @flg_lifi: flag change stack <-> queue
 * Description: carries values of the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *contnt;
	int flg_lifi;
}  bus_t;
extern bus_t bus;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_nbr);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
char  *clean_line(char *contnt);
void my_push(stack_t **head_stk, unsigned int nbr);
void my_pall(stack_t **head_stk, unsigned int nbr);
void my_pint(stack_t **head_stk, unsigned int nbr);
int execute(char *contnt, stack_t **head_stk, unsigned int cntr, FILE *file);
void free_stack(stack_t *head_stk);
void my_pop(stack_t **head_stk, unsigned int cntr);
void my_swap(stack_t **head_stk, unsigned int cntr);
void my_add(stack_t **head_stk, unsigned int cntr);
void my_nop(stack_t **head_stk, unsigned int cntr);
void my_sub(stack_t **head_stk, unsigned int cntr);
void my_div(stack_t **head_stk, unsigned int cntr);
void my_mul(stack_t **head_stk, unsigned int cntr);
void my_mod(stack_t **head_stk, unsigned int cntr);
void my_pchar(stack_t **head_stk, unsigned int cntr);
void my_pstr(stack_t **head_stk, unsigned int cntr);
void my_rotl(stack_t **head_stk, unsigned int cntr);
void my_rotr(stack_t **head_stk, __attribute__((unused)) unsigned int cntr);
void add_nod(stack_t **head_stk, int n);
void add_qu(stack_t **head_stk, int n);
void my_queue(stack_t **head_stk, unsigned int cntr);
void my_stack(stack_t **head_stk, unsigned int cntr);
ssize_t _getline(char **ln_ptr, size_t *n, FILE *strm);

#endif

