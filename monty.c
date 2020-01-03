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
	int fd = 0;
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
	fclose(argv[1]);
}

/**
 * read_file - function to read the file
 * @file: pointer to file to read
 * 
 */
void read_file (FILE *file)
{

	
}