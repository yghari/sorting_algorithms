#include "sort.h"

/**
 * print_array - Prints an array of integers.
 *
 * @arr: Pointer to the array to be printed.
 * @sz: Size of the array to be printed.
 */
void print_array(int *arr, size_t sz)
{
	size_t i;

	for (i = 0; i < sz; i++)
	{
		printf("%d", arr[i]);
		if (i < sz - 1)
			printf(", ");
	}
	printf("\n");
}
