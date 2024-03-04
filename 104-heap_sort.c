#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: 1st integer to swap.
 * @b: 2nd integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: Size of the array/tree.
 * @base: Index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order
 * @array: Array of integers.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int index;

	if (array == NULL || size < 2)
		return;

	for (index = (size / 2) - 1; index >= 0; index--)
		max_heapify(array, size, size, index);

	for (index = size - 1; index > 0; index--)
	{
		swap_ints(array, array + index);
		print_array(array, size);
		max_heapify(array, size, index, 0);
	}
}
