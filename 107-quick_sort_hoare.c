#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @arr: Pointer to the array.
 * @i: Index of the first element to swap.
 * @j: Index of the second element to swap.
 */
void swap(int *arr, size_t i, size_t j)
{
		int tmp = arr[i];

		arr[i] = arr[j];
		arr[j] = tmp;
}

/**
 * swap_and_print - Swaps two elements in an array and prints it.
 * @array: Pointer to the array.
 * @i: Index of the first element to swap.
 * @j: Index of the second element to swap.
 * @array_size: Size of the array.
 */
void swap_and_print(int *array, size_t i, size_t j, size_t array_size)
{
	if (i != j)
	{
		swap(array, i, j);
		print_array(array, array_size);
	}
}

/**
 * hoare_partition - Partitions an array around a pivot element.
 * @array: Pointer to the array to be partitioned.
 * @start_idx: Starting index of the subarray to be partitioned.
 * @end_idx: Ending index of the subarray to be partitioned.
 * @array_size: Size of the array.
 * Return: The pivot index.
 */
size_t hoare_partition(int *array, size_t start_idx,
				size_t end_idx, size_t array_size)
{
	size_t left_idx, right_idx;
	int pivot;

	left_idx = start_idx - 1;
	right_idx = end_idx + 1;
	pivot = array[end_idx];

	while (1)
	{
		do {
			left_idx++;
		}	while (array[left_idx] < pivot);
		do {
			right_idx--;
		}	while (array[right_idx] > pivot);
		if (left_idx >= right_idx)
			return (left_idx);
		swap_and_print(array, left_idx, right_idx, array_size);
		}
}

/**
 * quicksort_hoare - Helper function for the quicksort algorithm.
 * @array: Pointer to the array to be sorted.
 * @start_idx: Starting index of the subarray to be sorted.
 * @end_idx: Ending index of the subarray to be sorted.
 * @array_size: Size of the array.
 */
void quicksort_hoare(int *array, size_t start_idx,
			size_t end_idx, size_t array_size)
{
	size_t pivot_idx;

	if (start_idx < end_idx)
	{
		pivot_idx = hoare_partition(array, start_idx, end_idx, array_size);
		quicksort_hoare(array, start_idx, pivot_idx - 1, array_size);
		quicksort_hoare(array, pivot_idx, end_idx, array_size);
		}
}

/**
 * quick_sort_hoare - Quicksort algorithm using the Hoare partition scheme.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array != NULL && size > 1)
	{
		quicksort_hoare(array, 0, size - 1, size);
	}
}
