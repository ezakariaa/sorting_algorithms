#include "sort.h"
/**
* merge_sort - Function that sorts an array of integers in ascending order
* @array: pointer to array
* @size: the array's size
*/
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *temp_array = NULL;

	if (!array || size < 2)
		return;
	temp_array = malloc(size * sizeof(int));
	if (!temp_array)
		return;
	for (i = 0; i < size; i++)
		temp_array[i] = array[i];
	split(temp_array, 0, size, array);
	free(temp_array);
}

/**
 * split - Function that splits the array
 * @array: the array
 * @temp_array: Copy of original array
 * @left: Begin of array
 * @right: End of array
 */
void split(int *temp_array, size_t left, size_t right, int *array)
{
	int middle;

	if (right - left < 2)
		return;
	middle = (right + left) / 2;
	split(array, left, middle, temp_array);
	split(array, middle, right, temp_array);
	combine(temp_array, left, middle, right, array);
}

/**
 * combine - Function that prints and changes values of variables
 * @array: The original array
 * @temp_array: Copy of original array
 * @left: Beginning of array
 * @middle: Middle of array
 * @right: End of array
 */
void combine(int *array, size_t left, size_t middle,
	     size_t right, int *temp_array)
{
	size_t i = left,  j = middle, x = 0;

	printf("Merging...\n");
	printf("[left]: ");
	for (x = left; x < middle; x++)
	{
		if (x < middle - 1)
			printf("%d, ", array[x]);
		else
			printf("%d\n", array[x]);
	}
	printf("[right]: ");
	for (x = middle; x < right; x++)
	{
		if (x < right - 1)
			printf("%d, ", array[x]);
		else
			printf("%d\n", array[x]);
	}
	for (x = left; x < right; x++)
	{
		if (i < middle && (j >= right || array[i] <= array[j]))
		{
			temp_array[x] = array[i];
			i++;
		}
		else
		{
			temp_array[x] = array[j];
			j++;
		}
	}
	printf("[Done]: ");
	for (x = left; x < right; x++)
	{
		if (x < right - 1)
			printf("%d, ", temp_array[x]);
		else
			printf("%d\n", temp_array[x]);
	}
}
