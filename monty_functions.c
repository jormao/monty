#include "monty.h"

/**
 * _push_to_stack - pushes an element to the stack.
 * @value: Value to add to the node
 * @actual_head: address of the head
 *
 */

void _push_to_stack(stack_t **actual_head, unsigned int value)
{
	stack_t *new_node;
	stack_t *current = *actual_head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		error_function(4, NULL, value);
	new_node->n = value;
	new_node->next = *actual_head;
	new_node->prev = NULL;
	if (current != NULL)
		current->prev = new_node;
	head = new_node;
}

/**
 * _print_all_stack - pushes an element to the stack.
 * @line_number: line number with the command
 * @actual_head: address of the head
 *
 */
void _print_all_stack(stack_t **actual_head, unsigned int line_number)
{
	stack_t *tmp_node;

	(void)line_number;

	if (actual_head != NULL)
	{
		tmp_node = *actual_head;
		while (tmp_node != NULL)
		{
			printf("%d\n", tmp_node->n);
			tmp_node = tmp_node->next;
		}
	}
}

/**
 * free_dlistint - free a double linked list
 * @head: address of the head of double linked list
 *
 */

void free_dlistint(stack_t *head)
{
	if (head != NULL)
	{
		if (head->next != NULL)
			free_dlistint(head->next);
		free(head);
	}
}

/**
 * _print_top_stack - prints top element of stack
 * @actual_head: head of the dlistint
 * @line_number: line number of the command
 *
 */

void _print_top_stack(stack_t **actual_head, unsigned int line_number)
{
	stack_t *tmp_node;

	(void)line_number;
	tmp_node = *actual_head;
	if (*actual_head != NULL)
		printf("%i\n", tmp_node->n);
	else
		error_function(6, NULL, line_number);
}

/**
 * _remove_top_stack - deletes the node at top in the stack
 * @actual_head: pointer to beggin
 * @line_number: indicate the line number of command
 *
 */

void _remove_top_stack(stack_t **actual_head, unsigned int line_number)
{
	stack_t *tmp, *eraser;

	tmp = *actual_head;
	if (tmp == NULL)
		error_function(7, NULL, line_number);
	eraser = *actual_head;
	*actual_head = tmp->next;
	tmp = tmp->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	free(eraser);
}
