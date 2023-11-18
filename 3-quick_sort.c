#include "sort.h"

/**
 * quick_sort - A function that implements the quick sort
 * @array: The array to be sorted
 * @size: The size of the array
 *
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || !array)
		return;

	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - Recursively sorts parts of the array
 * @array: The array to be sorted
 * @low: The starting index of the array segment to be sorted
 * @high: The ending index of the array segment to be sorted
 * @size: The size of the array
 *
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int j;

		j = partition(array, low, high, size);
		quicksort(array, low, j - 1, size);
		quicksort(array, j + 1, high, size);
	}
}
/**
 * partition - Partitions the array into two segments
 * @array: The array to be partitioned
 * @low: The starting index for the partition
 * @high: The ending index for the partition
 * @size: The size of the array
 *
 * Return: The partition index
 *
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, i, j);
			if (i != j)
				print_array(array, size);
		}
	}
	if (array[high] < array[i + 1])
	{
		swap(array, i + 1, high);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap - Swaps two elements in an array
 * @array: The array containing the elements
 * @a: The index of the first element
 * @b: The index of the second element
 *
 */
void swap(int *array, size_t a, size_t b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}
