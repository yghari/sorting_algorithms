#include "sort.h"
/**
 * swap - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * bubble_sort - sorts an array of integers.
 * @array: array of integers to sort.
 * @size: size of the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size < 2 || array == NULL)
		return;
	for (i = size - 1; i >= 1; i--)
	{
		for (j = 1; j <= i; j++)
		{
			if (array[j - 1] > array[j])
			{
				swap(&array[j - 1], &array[j]);
				print_array(array, size);
			}
		}
	}
}

