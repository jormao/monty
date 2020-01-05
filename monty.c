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
	void (*operation)(stack_t **, unsigned int);
	int signo = 1, j = 0;
	unsigned int int_value = 0;

	operation = get_op_func(monty_opcode);
	if (operation)
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
			operation(&head, int_value);
		}
		else
			operation(&head, line_number);
		return;
	}
	error_function(3, monty_opcode, line_number);
}
