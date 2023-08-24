#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * read_opcode_file - Reads opcode instructions from a file and executes them.
 * @file: FILE pointer to the Monty bytecode file
 */
static void read_opcode_file(FILE *file)
{
	size_t bufsize = 0;
	char *line = NULL;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode;
	char *arg;
	int result = 0;


    while (getline(&line, &bufsize, file) != -1)
    {
        line_number++;

        opcode = strtok(line, " \t\n");
        if (opcode == NULL || *opcode == '#')
        {
            continue;
        }

        arg = strtok(NULL, " \t\n");
        result = execute_opcode(opcode, arg, &stack, line_number);
        if (result == -1)
        {
            fprintf(stderr, "Error: Unknown instruction '%s' at line %u\n", opcode, line_number);
            free_r(&stack);
            free(line);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    free_r(&stack);
    free(line);
    fclose(file);
}

/**
 * execute - Executes the opcode instructions in a Monty bytecode file.
 * @file_path: Path to the Monty bytecode file
 */
void execute(const char *file_path)
{
    FILE *file = fopen(file_path, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    read_opcode_file(file);
    fclose(file);
}
