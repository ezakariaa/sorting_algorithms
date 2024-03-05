#include "sort.h"

/**
 * max_int - Gets the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array
 */
int max_int(int *array, int size)
{
	int i, max;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_radix - Sorts the significant digits in ascending order
 * using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @signif: The significant digit to sort on.
 * @buffer: A bufferer to store the sorted array.
 */
void counting_radix(int *array, size_t size, int signif, int *buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / signif) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buffer[count[(array[i] / signif) % 10] - 1] = array[i];
		count[(array[i] / signif) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, signif, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	max = max_int(array, size);
	for (signif = 1; max / signif > 0; signif *= 10)
	{
		counting_radix(array, size, signif, buffer);
		print_array(array, size);
	}

	free(buffer);
}
