#include "sort.h"

/**
 * selection_sort - Sorts an array of integers using
 * the selection sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 *
 * Return: None.
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min, temp;

	if (size < 2 || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
