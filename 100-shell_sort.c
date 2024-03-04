#include "sort.h"

/**
 * swap_ints - Swaps two integers.
 * @x: The first int.
 * @y: The second int.
 */
void swap_ints(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: Array of integers.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t K, i, j;

	if (array == NULL || size < 2)
		return;

	for (K = 1; K < (size / 3);)
		K = K * 3 + 1;

	for (; K >= 1; K /= 3)
	{
		for (i = K; i < size; i++)
		{
			j = i;
			while (j >= K && array[j - K] > array[j])
			{
				swap_ints(array + j, array + (j - K));
				j -= K;
			}
		}
		print_array(array, size);
	}
}
