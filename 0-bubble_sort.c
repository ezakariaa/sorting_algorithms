#include "sort.h"
/**
 *bubble_sort - function that sorts an array of integers from min to max value
 *@array: an array
 *@size: array´s size
 *Return: nothing
 */


void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (size < 2 || !array)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
