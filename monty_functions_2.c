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

/**
 * _add_two_top_stack - swaps the top two elements of the stack.
 * @line_number: line number of the command in monty file
 * @actual_head: address of the head
 *
 */

void _add_two_top_stack(stack_t **actual_head, unsigned int line_number)
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
		tmp_value = tmp_node->n + tmp_node->next->n;
		tmp_node->next->n = tmp_value;
		_remove_top_stack(actual_head, line_number);
	}
	else
		error_function(9, NULL, line_number);
}

/**
 * _nop_does_anything - doesn’t do anything.
 * @line_number: line number of the command in monty file
 * @actual_head: address of the head
 *
 */

void _nop_does_anything(stack_t **actual_head, unsigned int line_number)
{
	(void)line_number;
	(void)actual_head;
}

/**
 * _sub_top_second_stack - subtracts top element from the second top elemen.
 * @line_number: line number of the command in monty file
 * @actual_head: address of the head
 *
 */

void _sub_top_second_stack(stack_t **actual_head, unsigned int line_number)
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
		tmp_value = tmp_node->next->n - tmp_node->n;
		tmp_node->next->n = tmp_value;
		_remove_top_stack(actual_head, line_number);
	}
	else
		error_function(10, NULL, line_number);
}

/**
 * _div_second_top_stack - divides second top element by the top of stack.
 * @line_number: line number of the command in monty file
 * @actual_head: address of the head
 *
 */

void _div_second_top_stack(stack_t **actual_head, unsigned int line_number)
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
		tmp_value = tmp_node->next->n / tmp_node->n;
		tmp_node->next->n = tmp_value;
		_remove_top_stack(actual_head, line_number);
	}
	else
		error_funct_2(11, line_number);
}
