#include "monty.h"

/**
  * get_op_func - find the specific opcode function to use
  * @s: string with monty instruction
  *
  * Return: always pointer to function o NULL
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
		{"sub", _sub_top_second_stack},
		{"div", _div_second_top_stack},
		{"mul", _mul_second_top_stack},
		{"mod", _mod_second_top_stack},
		{"pchar", _print_char_top_stack},
		{"pstr", _print_string_top_stack},
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
