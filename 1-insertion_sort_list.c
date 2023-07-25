#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the insertion sort algorithm
 *
 * @list: Pointer to pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *next, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cur = (*list)->next;

	while (cur != NULL)
	{
		next = cur->next;
		temp = cur;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			if (temp->prev->prev != NULL)
				temp->prev->prev->next = temp;
			else
				*list = temp;

			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			temp->prev->next = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			print_list(*list);
		}

		cur = next;
	}
}
