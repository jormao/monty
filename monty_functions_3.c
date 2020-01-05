#include "monty.h"

/**
 * _mul_second_top_stack -  multiplies second top element by top element stack
 * @line_number: line number of the command in monty file
 * @actual_head: address of the head
 *
 */

void _mul_second_top_stack(stack_t **actual_head, unsigned int line_number)
{
	stack_t *tmp_node = *actual_head;
	int count = 0, tmp_value = 0;

	while (tmp_node)
	{
		tmp_node = tmp_node->next;
		count++;
	}
	if (count >= 2)
	{
		tmp_node = *actual_head;
		tmp_value = tmp_node->next->n * tmp_node->n;
		tmp_node->next->n = tmp_value;
		_remove_top_stack(actual_head, line_number);
	}
	else
		error_funct_2(13, line_number);
}

/**
 * _mod_second_top_stack - compute rest div second top element by top of stack
 * @line_number: line number of the command in monty file
 * @actual_head: address of the head
 *
 */

void _mod_second_top_stack(stack_t **actual_head, unsigned int line_number)
{
	stack_t *tmp_node = *actual_head;
	int count = 0, tmp_value = 0;

	while (tmp_node)
	{
		tmp_node = tmp_node->next;
		count++;
	}
	if (count >= 2)
	{
		tmp_node = *actual_head;
		if (tmp_node->n == 0)
			error_funct_2(12, line_number);
		tmp_value = tmp_node->next->n % tmp_node->n;
		tmp_node->next->n = tmp_value;
		_remove_top_stack(actual_head, line_number);
	}
	else
		error_funct_2(14, line_number);
}
