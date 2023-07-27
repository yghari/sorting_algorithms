#include "sort.h"

/**
 * swap_left_right - swaps nodes from left to right
 * @list: pointer to the doubly linked list
 * @head: pointer to the head of the list
 * @node: pointer to the node to be swapped
 */
void swap_left_right(listint_t **list, listint_t *head, listint_t *node)
{
	if (head->prev)
		head->prev->next = node;
	else
		*list = node;
	if (node->next)
		node->next->prev = head;
	head->next = node->next;
	node->prev = head->prev;
	node->next = head;
	head->prev = node;
	print_list(*list);
}

/**
 * swap_right_left - swaps nodes from right to left
 * @list: pointer to the doubly linked list
 * @head: pointer to the head of the list
 * @node: pointer to the node to be swapped
 */
void swap_right_left(listint_t **list, listint_t *head, listint_t *node)
{
	listint_t *aux;
	(void)*node;

	aux = head->prev;
	aux->next->prev = aux->prev;
	if (aux->prev)
		aux->prev->next = aux->next;
	else
		*list = aux->next;
	aux->prev = aux->next;
	aux->next = aux->next->next;
	aux->prev->next = aux;
	if (aux->next)
		aux->next->prev = aux;
	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 * @list: pointer to the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *aux;
	int swapped = 1;

	/* Check for empty or NULL list */
	if (list == NULL || *list == NULL)
		return;

	current = *list;
	while (swapped == 1)
	{
		swapped = 0;
		/* Iterate over the list from left to right */
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				aux = current->next;
				swap_left_right(list, current, aux);
				swapped = 1;
			}
			else
				current = current->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		/* Iterate over the list from right to left */
		while (current->prev != NULL)
		{
			if (current->prev->n > current->n)
			{
				aux = current->prev;
				swap_right_left(list, current, aux);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
