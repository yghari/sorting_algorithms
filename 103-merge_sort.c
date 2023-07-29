#include "sort.h"
/**
 * _calloc - allocates memory for an array using calloc
 * @nmemb: number of elements
 * @size: size of each element
 *
 * Return: pointer to the allocated memory, or NULL if nmemb or size is 0
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		ptr[i] = 0;

	return (ptr);
}

/**
 * merge - merges two subarrays of arr[]
 * @arr: array to be sorted
 * @tmp: temporary array used in merge to optimize reducing system calls
 * @start: starting index of left subarray
 * @mid: ending index of left subarray and starting index of right subarray
 * @end: ending index of right subarray
 *
 * Description: This function merges two subarrays of arr[], the left and right
 * subarrays, both of which are sorted in ascending order.
 */
void merge(int *arr, int *tmp, int start, int mid, int end)
{
	int left_size = mid - start + 1, right_size = end - mid;
	int *left_arr, *right_arr;
	int left_index, right_index, i = 0;

	left_arr = &tmp[0];
	right_arr = &tmp[right_size];

	for (left_index = 0; left_index < left_size; left_index++)
		left_arr[left_index] = arr[start + left_index];
	for (right_index = 0; right_index < right_size; right_index++)
		right_arr[right_index] = arr[mid + 1 + right_index];

	left_index = 0, right_index = 0, i = start;

	while (left_index < left_size && right_index < right_size)
	{
		if (left_arr[left_index] <= right_arr[right_index])
			arr[i] = left_arr[left_index], left_index++;
		else
			arr[i] = right_arr[right_index], right_index++;
		i++;
	}

	while (left_index < left_size)
		arr[i] = left_arr[left_index], left_index++, i++;
	while (right_index < right_size)
		arr[i] = right_arr[right_index], right_index++, i++;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left_arr, left_index);
	printf("[right]: ");
	print_array(right_arr, right_index);
	printf("[Done]: ");
	print_array(&arr[start], left_index + right_index);
}

/**
 * mergesort - sorts an array of integers in ascending order using Merge sort
 * @array: array of integers to be sorted
 * @tmp: temporary array used in merge to optimize reducing system calls
 * @start: starting index of the array
 * @end: ending index of the array
 *
 * Description: This function sorts an array of integers in ascending order
 * using the Merge sort algorithm. It recursively divides the input array into
 * two halves, sorts them independently, and then merges the two sorted halves
 * to produce the final sorted array.
 */
void mergesort(int *array, int *tmp, int start, int end)
{
	int mid;

	mid = (start + end) / 2;
	if ((start + end) % 2 == 0)
		mid--;
	if (mid >= start)
	{
		mergesort(array, tmp, start, mid);
		mergesort(array, tmp, mid + 1, end);
		merge(array, tmp, start, mid, end);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order using Merge sort
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 * Description: This function sorts an array of integers in ascending order
 * using the Merge sort algorithm. It allocates a temporary array using calloc
 * to optimize reducing system calls and then calls the mergesort function to
 * perform the actual sorting. Finally, it frees the temporary array.
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = _calloc(size, sizeof(int));
	mergesort(array, tmp, 0, size - 1);
	free(tmp);
}
