#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

#define MAX_LINE_LENGTH 128

stack_t *top = NULL;

/**
 * main - An entry point into the monty interpreter
 * @argc: the argument count
 * @argv: the argument vector
 *
 * @Return: 0 if successful else appropriate error code
 */
int main(int argc, char **argv)
{
	FILE *file;
	char line[MAX_LINE_LENGTH] = {0};
	unsigned int line_count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!(file = fopen(argv[1],"r")))
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Get each line until there are none left */
	while (fgets(line, MAX_LINE_LENGTH, file))
	{
		/* Print each line */
		printf("L%d: %s", ++line_count, line);
		/* Add a trailing \n to lines that don't already have one */
		if (line[strlen(line) - 1] != '\n')
			printf("\n");
	}
	return (0);
}
