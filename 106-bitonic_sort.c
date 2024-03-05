#include "sort.h"


/**
 * swap_ints - swaps two integers.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap_ints(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * merge_bito - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @beg: The beginning index of the sequence.
 * @size_seq: The size of the sequence.
 * @direc: The direction to sort in.
 */
void merge_bito(int *array, size_t size, size_t beg, size_t size_seq,
		char direc)
{
	size_t i, j = size_seq / 2;

	if (size_seq > 1)
	{
		for (i = beg; i < beg + j; i++)
		{
			if ((direc == UP && array[i] > array[i + j]) ||
			    (direc == DOWN && array[i] < array[i + j]))
				swap_ints(array + i, array + i + j);
		}
		merge_bito(array, size, beg, j, direc);
		merge_bito(array, size, beg + j, j, direc);
	}
}

/**
 * convert_bito - Converts an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @beg: The beginning index of a block of the building bitonic sequence.
 * @size_seq: The size of a block of the building bitonic sequence.
 * @direc: The direction to sort the bitonic sequence block in.
 */
void convert_bito(int *array, size_t size, size_t beg, size_t size_seq,
		char direc)
{
	size_t cut = size_seq / 2;
	char *str = (direc == UP) ? "UP" : "DOWN";

	if (size_seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", size_seq, size, str);
		print_array(array + beg, size_seq);

		convert_bito(array, size, beg, cut, UP);
		convert_bito(array, size, beg + cut, cut, DOWN);
		merge_bito(array, size, beg, size_seq, direc);

		printf("Result [%lu/%lu] (%s):\n", size_seq, size, str);
		print_array(array + beg, size_seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	convert_bito(array, size, 0, size, UP);
}
