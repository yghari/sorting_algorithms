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
 * bubble_sort - Sorts an array of integers using the bubble sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array to be sorted.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	if (size < 2 || array == NULL)
		return;

	for (i = size - 1; i >= 1; i--)
	{
		swapped = false;
		for (j = 1; j <= i; j++)
		{
			if (array[j - 1] > array[j])
			{
				swaping(&array[j - 1], &array[j]);
				print_array(array, size);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}
