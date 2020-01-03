#include "monty.h"

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
		error_function(1);
	if (argv[1] == NULL)
		error_function(2);
	if (access (argv[1], R_OK) == -1)
		error_function(3);
	file = fopen(argv[1], "r");
	if (file == NULL)
		error_function(3);
	read_file(file);
	fclose(file);
	return (0);
}

/**
 * read_file - function to read the file
 * @file: pointer to file to read
 * 
 */
	void read_file (FILE *file)
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
 * 
 */
void error_function (int error_number)
{
	error_number++;

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

	if (lineptr == NULL)
		error_function(4);
	delim = "\n ";
	opcode = strtok(lineptr, delim);
	value = strtok(NULL, delim);

	if (opcode != NULL)
	{
		printf("value = %s\n", value);
		printf("opcode = %s\n", opcode);
		printf("line_number = %d\n", line_number);
		_opcode_function(char *value, char *opcode, int line_number);
	}
}

/**
  * _opcode_function - find the specific opcode function to use
  * @value: Value to manipulate
  * @opcode: string with monty instruction
  * @line_number: the line where is the instruction 
  *
  */
void _opcode_function(char *value, char *monty_opcode, int line_number)
{
	int i = 0;
	instruction_t _functions[] = {
		{"push", _push_to_stack},
		{"pall", _print_all_stack},
		{NULL, NULL}
	};

	while (_functions[i].opcode)
	{
		if (strcmp(_functions[i].opcode, monty_opcode) == 0)
			_functions[i].f()

	}
}
