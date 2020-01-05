#include "monty.h"

/**
  * _opcode_function - find the specific opcode function to use
  * @value: Value to manipulate
  * @monty_opcode: string with monty instruction
  * @line_number: the line where is the instruction
  *
  */

void (*get_op_func(char *s))(stack_t **, unsigned int)
{
	instruction_t _functions[] = {
		{"push", _push_to_stack},
		{"pall", _print_all_stack},
		{"pint", _print_top_stack},
		{"pop", _remove_top_stack},
		{"swap", _swap_two_top_stack},
		{"add", _add_two_top_stack},
		{"nop", _nop_does_anything},
		{NULL, NULL}
	};
	int i = 0;

	while (_functions[i].opcode)
	{
		if (!(strcmp(_functions[i].opcode, s)))
			return (_functions[i].f);
		i++;
	}
	return (NULL);
}