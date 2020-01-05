#include "monty.h"

/**
 * _swap_two_top_stack - swaps the top two elements of the stack.
 * @line_number: line number of the command in monty file
 * @actual_head: address of the head
 *
 */
void _swap_two_top_stack(stack_t **actual_head, unsigned int line_number)
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
		tmp_value = tmp_node->n;
		tmp_node->n = tmp_node->next->n;
		tmp_node->next->n = tmp_value;
	}
	else
		error_function(8, NULL, line_number);
}