#include "sort.h"

/**
 * swap_ints - swaps two integers.
 * @x: The first int.
 * @y: The second int.
 */
void swap_ints(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *k;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		k = array + i;
		for (j = i + 1; j < size; j++)
			k = (array[j] < *k) ? (array + j) : k;

		if ((array + i) != k)
		{
			swap_ints(array + i, k);
			print_array(array, size);
		}
	}
}
