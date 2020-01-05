#include "monty.h"

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
		case 8:
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
			break;
		case 9:
			fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
			break;
		case 10:
			fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
			break;
	default:
		return;
	}
	free_dlistint(head);
	exit(EXIT_FAILURE);
}

/**
 * error_funct_2 - function to print in stderr all the errors
 * @error_number: number of the error
 * @line_number: line of the monty file that is readed.
 *
 */
void error_funct_2(int error_number, int line_number)
{
	switch (error_number)
	{
		case 11:
			fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
			break;
		case 12:
			fprintf(stderr, "L%d: division by zero\n", line_number);
			break;
		case 13:
			fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
			break;
		case 14:
			fprintf(stderr, "L<%d: can't mod, stack too short\n", line_number);
			break;
		case 15:
			fprintf(stderr, "L%d: division by zero\n", line_number);
			break;
	default:
		return;
	}
	free_dlistint(head);
	exit(EXIT_FAILURE);
}
