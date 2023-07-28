#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _getline - read string of text.
 * @ln_ptr: dynamically allocated buffer.
 * @n: number of characters in the line.
 * @strm: the file to read from.
 * Return: number of characters read
 * and stored in the buffer.
 */
ssize_t _getline(char **ln_ptr, size_t *n, FILE *strm)
{
	size_t init_size;
	size_t total_chars = 0;
	int c;

	init_size = 32;
	if (ln_ptr == NULL || n == NULL || strm == NULL)
		return (-1);

	if (*ln_ptr == NULL || *n == 0)
	{
		*ln_ptr = (char *)malloc(init_size);
		if (*ln_ptr == NULL)
			return (-1);
		*n = init_size;
	}

	while ((c = fgetc(strm)) != EOF)
	{
		if (total_chars >= *n - 1)
		{
			size_t new_size = *n * 2;
			char *new_lineptr = (char *)realloc(*ln_ptr, new_size);

			if (new_lineptr == NULL)
				return (-1);
			*ln_ptr = new_lineptr;
			*n = new_size;
		}
		(*ln_ptr)[total_chars++] = c;

		if (c == '\n')
			break;
	}

	(*ln_ptr)[total_chars] = '\0';
	return (total_chars);
}
