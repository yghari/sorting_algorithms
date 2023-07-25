#include "sort.h"

/**
 * swaping - Swaps two integer values.
 *
 * @first: Pointer to the first value to be swapped.
 * @second: Pointer to the second value to be swapped.
 */
void swaping(int *first, int *second)
{
	int tmp = *first;
	*first = *second;
	*second = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, smallest;

	for (i = 0; i < size; i++)
	{
		smallest = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest])
				smallest = j;
		}
		if (smallest != i)
		{
			swap(&array[i], &array[smallest]);
			print_array(array, size);
		}
	}
}
