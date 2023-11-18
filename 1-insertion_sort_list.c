#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm.
 *
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		tmp = current;
		prev = current->prev;

		while (prev != NULL && prev->n > tmp->n)
		{
			prev->next = tmp->next;

			if (tmp->next != NULL)
				tmp->next->prev = prev;

			tmp->prev = prev->prev;
			tmp->next = prev;
			prev->prev = tmp;

			if (tmp->prev != NULL)
				tmp->prev->next = tmp;
			else
				*list = tmp;

			prev = tmp->prev;
			print_list(*list);
		}

		current = current->next;
	}
}
