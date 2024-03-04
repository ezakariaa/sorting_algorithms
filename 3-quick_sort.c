#include "sort.h"

/**
 * swap_ints - swaps two integers.
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
 * partition - lomuto partition scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @low: The lowest int.
 * @high: The highest int.
 *
 * Return: The final partition index.
 */
int partition(int *array, size_t size, int low, int high)
{
	int *pivot, j, i;

	pivot = array + high;
	for (j = i = low; i < high; i++)
	{
		if (array[i] < *pivot)
		{
			if (j < i)
			{
				swap_ints(array + i, array + j);
				print_array(array, size);
			}
			j++;
		}
	}

	if (array[j] > *pivot)
	{
		swap_ints(array + j, pivot);
		print_array(array, size);
	}

	return (j);
}
/**
 * sort_lomuto - implements the quicksort algorithm through recursion.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @low: The lowest int.
 * @high: The highest int.
 */
void sort_lomuto(int *array, size_t size, int low, int high)
{
	int p;

	if (high - low > 0)
	{
		p = partition(array, size, low, high);
		sort_lomuto(array, size, low, p - 1);
		sort_lomuto(array, size, p + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort_lomuto(array, size, 0, size - 1);
}
