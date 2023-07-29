#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * max_heapify - recursively heapifies a subtree rooted at i, ensures that
 * the subtree rooted at i is a max heap
 * @arr: array to be sorted
 * @s: size of the array
 * @i: index of the subtree
 * @n: size of the subtree
 */
void max_heapify(int *arr, size_t s, int i, size_t n)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < (int)n && arr[left] > arr[largest])
		largest = left;

	if (right < (int)n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		print_array(arr, s);
		max_heapify(arr, s, largest, n);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order using the
 * Heap sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 * Description: This function sorts an array of integers in ascending order
 * using the Heap sort algorithm. It first creates a max heap from the input
 * array, then repeatedly extracts the maximum element from the heap and places
 * it at the end of the array to produce the final sorted array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	/* Build max heap */
	for (i = (size - 2) / 2; i >= 0; --i)
		max_heapify(array, size, i, size);

	/* Extract max element and swap with last element, then re-heapify */
	for (i = size - 1; i > 0; --i)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		max_heapify(array, size, 0, i);
	}
}
