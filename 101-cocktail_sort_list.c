#include "sort.h"
/**
 * swap_nodes - Swaps positions of two nodes in a doubly linked list.
 * @a: First node to be swapped.
 * @b: Second node to be swapped.
 */
void swap_nodes(listint_t *a, listint_t *b)
{
	int tmp;

	/*type casting: casting away "const" to allow modification of n*/
	tmp = *((int *)&(a->n));
	*((int *)&(a->n)) = *((int *)&(b->n));
	*((int *)&(b->n)) = tmp;
}
/**
 * cocktail_sort_list - Sorts a d-linked list-the cocktail sort algorithm.
 * @list: Double pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = NULL;
	listint_t *end = NULL;
	listint_t *current;

	if (*list == NULL)
		return;
	do {
		swapped = 0;
		current = *list;

		/*forward iteration*/
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next);
				print_list(*list);
				swapped = 1;
			}
			current = current->next;
		}
		end = current;
		/*check the list if sorted*/
		if (!swapped)
			break;
		/*Backward iteration*/
		swapped = 0;
		while (current != start)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current, current->prev);
				print_list(*list);
				swapped = 1;
			}
			current = current->prev;
		}
		start = current;
	} while (swapped);
}
