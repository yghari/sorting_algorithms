#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swaping - Swap two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swaping(int *a, int *b)
{
		int temp = *a;
		*a = *b;
		*b = temp;
}

/**
 * partition - Partition an array using the Lomuto scheme
 * @array: Pointer to the array
 * @low: Index of the low end of the partition
 * @high: Index of the high end of the partition
 *
 * Return: The final index of the pivot element after partitioning
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swaping(&array[i], &array[j]);
			print_array(array, high + 1);
		}
	}
	swaping(&array[i + 1], &array[high]);
	print_array(array, high + 1);
	return (i + 1);
}

/**
 * quicksort - Sort an array using the Quick sort algorithm
 * @array: Pointer to the array
 * @low: Index of the low end of the partition
 * @high: Index of the high end of the partition
 */
void quicksort(int *array, int low, int high)
{
	int partition_index;

	if (low < high)
	{
		partition_index = partition(array, low, high);
		quicksort(array, low, partition_index - 1);
		quicksort(array, partition_index + 1, high);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: Pointer to the array
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1);
}
