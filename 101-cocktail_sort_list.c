#include "sort.h"

void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a == NULL || b == NULL || a == b)
		return;

	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next && b->next != a)
		b->next->prev = a;

	a->next= b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = NULL;
	listint_t *end = NULL;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped =0;
		current = *list;

		/* Forward iteration */
		while (current != end && current->next != NULL)
		{
			if (current->n > current->next->n) {
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			current = current->next;
		}
		end = current;
		/* Check if the list is sorted */
		if (!swapped)
			break;
		/* Backward iteration */
		swapped = 0;
		while (current != start)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current, current->prev);
				print_list(*list);
				swapped = 1;
			}
			current =current->prev;
		}
		start = current;
	} while (swapped);
}
