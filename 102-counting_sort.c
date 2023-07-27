#include "sort.h"

/**
 * counting_sort - sorts an integer array using
 * @array: pointer to the integer array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max_value, j, *output_array, *count_array;
	size_t i;

	if (!array || size < 2)
		return;

	max_value = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	count_array = calloc((max_value + 1), sizeof(int));
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]++;
	}
	for (j = 1; j <= max_value; j++)
	{
		count_array[j] += count_array[j - 1];
	}
	print_array(count_array, max_value + 1);
	output_array = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]--;
		output_array[count_array[array[i]]] = array[i];
	}

	/* Copy the sorted values back into the input array */
	for (i = 0; i < size; i++)
	{
		array[i] = output_array[i];
	}

	/* Free the output and count arrays to avoid memory leaks */
	free(output_array);
	free(count_array);
}
