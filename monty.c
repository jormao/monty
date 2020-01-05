#include "monty.h"
stack_t *head = NULL;

/**
 * main - function main for begin the program
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: always 0
 */

int main(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
		error_function(1, argv[1], argc);
	if (access(argv[1], R_OK) == -1)
		error_function(2, argv[1], argc);
	file = fopen(argv[1], "r");
	if (file == NULL)
		error_function(2, argv[1], argc);
	read_file(file);
	fclose(file);
	free_dlistint(head);
	return (0);
}

/**
 * read_file - function to read the file
 * @file: pointer to file to read
 *
 */
	void read_file(FILE *file)
	{

	char *lineprt = NULL;
	size_t n = 0;
	int line_number = 1;

	while (getline(&lineprt, &n, file) != EOF)
	{
		split_string(lineprt, line_number);
		line_number++;
	}
	free(lineprt);
}

/**
 * error_function - function to print in stderr all the errors
 * @error_number: number of the error
 * @file_name: name of the file with bitcode
 * @line_number: line of the monty file that is readed.
 *
 */
void error_function(int error_number, char *file_name, int line_number)
{
	switch (error_number)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", file_name);
			break;
		case 3:
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, file_name);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			break;
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
			break;	
	default:
		return;
	}
	free_dlistint(head);
	exit(EXIT_FAILURE);
}

/**
 * split_string - Separates by lines to determinate the function to use
 * @lineptr: String representing a line in a file.
 * @line_number: Line number for the opcode.
 *
 */
void split_string(char *lineptr, int line_number)
{
	char *delim;
	char *opcode;
	char *value;

	delim = "\n ";
	opcode = strtok(lineptr, delim);
	value = strtok(NULL, delim);

	if (opcode != NULL)
		_opcode_function(value, opcode, line_number);
}

/**
  * _opcode_function - find the specific opcode function to use
  * @value: Value to manipulate
  * @monty_opcode: string with monty instruction
  * @line_number: the line where is the instruction
  *
  */
void _opcode_function(char *value, char *monty_opcode, int line_number)
{
	int i = 0, signo = 1, j = 0, int_value = 0, valid_inst = 0;
	instruction_t _functions[] = {
		{"push", _push_to_stack},
		{"pall", _print_all_stack},
		{"pint", _print_top_stack},
		{"pop", _remove_top_stack},
		{NULL, NULL}
	};

	while (_functions[i].opcode)
	{
		if (strcmp(_functions[i].opcode, monty_opcode) == 0)
		{
			if (strcmp(monty_opcode, "push") == 0)
			{
				if (value == NULL)
					error_function(5, monty_opcode, line_number);
				else if (value[0] == '-')
				{
					value = value + 1;
					signo = (signo * -1);
				}
				while (value[j])
				{
					if (isdigit(value[j]) == 0)
						error_function(5, monty_opcode, line_number);
						j++;
				}
				int_value = atoi(value) * signo;
				_functions[i].f(&head, int_value);
			}
			else
				_functions[i].f(&head, line_number);
			valid_inst = 1;
		}
		i++;
	}
	if (valid_inst == 0)
		error_function(3, monty_opcode, line_number);
}
