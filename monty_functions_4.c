#include "monty.h"

/**
 * _rotate_stack_bottom - rotates the stack to the bottom
 * @actual_head: head of the dlistint
 * @line_number: line number of the command
 *
 */

void _rotate_stack_bottom(stack_t **actual_head, unsigned int line_number)
{
	stack_t *tmp_node;
	int tmp_value = 0, tmp_value_n = 0, count = 0;

	(void)line_number;
	tmp_node = *actual_head;
	while (tmp_node)
	{
		tmp_value = tmp_node->n;
		tmp_node = tmp_node->next;
		count++;
	}
	tmp_node = *actual_head;
	if (count > 1)
	{
		while (tmp_node->next)
		{
			tmp_value_n = tmp_node->n;
			tmp_node->n = tmp_value;
			tmp_value = tmp_value_n;
			tmp_node = tmp_node->next;
		}
		tmp_node->n = tmp_value;
	}
}

/**
 * _push_in_queue - pushes an element to the queue.
 * @value: Value to add to the node
 * @actual_head: address of the head
 *
 */

void _push_in_queue(stack_t **actual_head, unsigned int value)
{

	stack_t *new_node;
	stack_t *last;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		error_function(4, NULL, value);
	last = *actual_head;
	new_node->n = value;
	new_node->next = NULL;
	if (*actual_head == NULL)
	{
		head = new_node;
		new_node->prev = NULL;
		return;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new_node;
	new_node->prev = last;
}
