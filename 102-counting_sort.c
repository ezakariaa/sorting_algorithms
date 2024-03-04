#include "sort.h"

/**
 * max_int - Gets the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int max_int(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *s, max, i;

	if (array == NULL || size < 2)
		return;

	s = malloc(sizeof(int) * size);
	if (s == NULL)
		return;
	max = max_int(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(s);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		s[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = s[i];

	free(s);
	free(count);
}
